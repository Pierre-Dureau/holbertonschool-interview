#!/usr/bin/python3
"""Module to count the occurrences of words in the titles of hot posts"""
import requests


def count_words(subreddit, word_list, count={}, after=None):
    """
    Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {"User-Agent": "MonScriptPython/1.0"}
    params = {'after': after} if after else {}

    response = requests.get(url, headers=headers, params=params)

    if response.status_code == 200:
        data = response.json().get("data")
        for post in data.get("children"):
            for word in post.get('data').get('title').lower().split():
                for list in word_list:
                    if list.lower() == word:
                        if word in count.keys():
                            count[word] += 1
                        else:
                            count[word] = 1

        if 'after' in data and data.get("after"):
            return count_words(subreddit, word_list, count, data.get("after"))

        count = dict(sorted(count.items(), key=lambda item: item[1],
                            reverse=True))
        for key, value in count.items():
            print(f"{key}: {value}")
    else:
        return
