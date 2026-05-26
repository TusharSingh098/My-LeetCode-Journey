import os
import re
import requests

def fetch_leetcode_metadata(title_slug):
    """Hits the LeetCode GraphQL API to get difficulty and topic tags."""
    url = "https://leetcode.com/graphql/"
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        difficulty
        topicTags {
          name
        }
      }
    }
    """
    variables = {"titleSlug": title_slug}
    
    try:
        response = requests.post(url, json={"query": query, "variables": variables})
        if response.status_code == 200:
            data = response.json().get('data', {}).get('question')
            if data:
                difficulty = data.get('difficulty', 'Unknown')
                tags = data.get('topicTags', [])
                
                if tags:
                    topics = ', '.join([f"`{tag['name']}`" for tag in tags])
                else:
                    topics = "`No Tags`"
                    
                return difficulty, topics
    except Exception as e:
        print(f"API Request failed for {title_slug}: {e}")
        
    return 'Unknown', '`Unknown`'

def generate_table():
    print("Scanning folders and querying LeetCode API (this takes a few seconds)...")
    folders = [f for f in os.listdir('.') if os.path.isdir(f) and re.match(r'^\d{4}-', f)]
    folders.sort()

    table = "<details open>\n<summary><b>View Solved Algorithms</b></summary>\n\n"
    table += "| ID | Problem Name | Difficulty | Core Concepts |\n| :--- | :--- | :--- | :--- |\n"
    
    for folder in folders:
        # '0001-two-sum' -> ID: '0001', Slug: 'two-sum'
        parts = folder.split('-')
        prob_id = parts[0]
        title_slug = '-'.join(parts[1:])
        prob_name = title_slug.replace('-', ' ').title()
        
        # Fetch clean data directly from LeetCode
        difficulty, topics = fetch_leetcode_metadata(title_slug)
        
        link = f"[{prob_name}](https://github.com/TusharSingh098/My-LeetCode_Journey/tree/main/{folder}/)"
        table += f"| {prob_id} | {link} | {difficulty} | {topics} |\n"
        
    table += "\n</details>"
    return table

def update_readme():
    with open('README.md', 'r', encoding='utf-8') as file:
        content = file.read()

    start_marker = "\n"
    end_marker = ""
    
    start_idx = content.find(start_marker)
    end_idx = content.find(end_marker)

    if start_idx != -1 and end_idx != -1:
        new_table = generate_table()
        new_content = content[:start_idx + len(start_marker)] + new_table + "\n" + content[end_idx:]
        
        with open('README.md', 'w', encoding='utf-8') as file:
            file.write(new_content)
        print("README successfully updated!")
    else:
        print("CRITICAL: Could not find injection markers in README.md")

if __name__ == "__main__":
    update_readme()
