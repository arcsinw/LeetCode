import requests
import jsonpickle
from requests_html import HTMLSession
from requests_html import HTML
import os


class Blog:
    title = ''
    href = ''


def isAc(problem):
    if problem['status'] == "ac":
        return True
    return False


difficulty_dic = {
    1: "Easy",
    2: "Medium",
    3: "Hard"
}


def getDifficulty(difficulty):
    return difficulty_dic[difficulty]


if __name__ == "__main__":
    blog_url = "https://www.cnblogs.com/arcsinw/default.html?page=%s"
    blog_pageIndex = 1

    leetcode_url = "https://leetcode.com/api/problems/all/"

    session = HTMLSession()
    blogs = []

    while (True):
        print("current: %s" % blog_pageIndex)
        response = session.get(blog_url % blog_pageIndex)
        blog_pageIndex = blog_pageIndex + 1
        items = response.html.find('div.postTitle')
        if (len(items) == 0):
            break

        for item in items:
            blog = Blog()
            a = HTML(html=item.html).find('a', first=True)
            if (a):
                blog.title = a.text
                blog.href = a.attrs['href']

            blogs.append(blog)

    leetcode_headers = {
        # 'Accept': 'application/json, text/javascript, */*; q=0.01',
        # 'Accept-Encoding': 'gzip, deflate, br',
        # 'Accept-Language': 'zh-CN,zh;q=0.9',
        # 'Content-Type': 'application/json',
        'Cookie': '',
        # 'Referer': 'https://leetcode.com/problemset/all/?status=Solved',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.119 Safari/537.36',
        # 'X-Requested-With': 'XMLHttpRequest',
    }

    leetcode_request = requests.Session()
    leetcode_response = leetcode_request.get(
        url=leetcode_url, headers=leetcode_headers)

    problems = leetcode_response.json()['stat_status_pairs']

    readme = ('## LeetCode' + os.linesep +
              '|#|Title|Difficulty|Code|Blog|' + "\n" +
              '| :---: | :---: | :---: | :---: | :---: |' + "\n")

    solved_problems = list(filter(isAc, problems))
    solved_problems = sorted(
        solved_problems, key=lambda p: p['stat']['frontend_question_id'])

    for problem in solved_problems:
        problem_id = str(problem['stat']['frontend_question_id'])
        problem_title = problem['stat']['question__title']
        problem_href = 'https://leetcode.com/problems/' + \
            problem['stat']['question__title_slug']
        problem_difficulty = getDifficulty(problem['difficulty']['level'])

        if (problem_id):

            blog = list(filter(lambda x: (x.title.find('[LeetCode] ' + problem_id + '. ' +
                                                       problem_title) != -1), blogs))
            blog_href = ''
            blog_title = ''
            if (len(blog) > 0):
                blog_href = blog[0].href
                blog_title = blog[0].title

            line = "|" + problem_id + "|" + \
                "[" + problem_title + \
                "](" + problem_href + ")" + "|" + problem_difficulty + "|" + "[" + problem_id + ".cpp" + \
                "](" + "src/" + problem_id + ".cpp)" + \
                "|[" + blog_title + "](" + blog_href + ")|"
            readme += line
            readme += "\n"

    print(readme)
    fd = open('README.md', 'w', encoding='utf-8')
    fd.write(readme)
    fd.close()
