/**
 * a spider to get my blog's title and link about LeetCode
 * from https://i.cnblogs.com/posts
 */


function sleep(delay) {
    var start = (new Date()).getTime();
    while ((new Date()).getTime() - start < delay) {
        continue;
    }
}

var pageIndex = 1;
var blogs = new Array();

//while (true) {
var tbody = document.querySelector('div#post_list tbody');
// if (tbody.childElementCount == 1) {
//     break;
// }

for (var j = 1; j < tbody.childElementCount; j++) {
    var blog = new Object();
    blog.title = tbody.children[j].querySelector('td.post-title > a').innerText;
    blog.href = tbody.children[1].querySelector('td.post-title > a').href;
    blogs.push(blog);
}

function getBlogById(id) {
    for (var k = 0; k < blogs.length; k++) {
        if (blogs[i].name.indexOf(id) != -1) {
            return blogs[i];
        }
    }

    return null;
}

//location.href = "https://i.cnblogs.com/posts?page=" + pageIndex++;
//sleep(10);
//}



/**
 * get finished problem's # and title 
 * from https://leetcode.com/problemset/all/?status=Solved
 */

var problems = new Array();

var problem_table = document.getElementsByClassName('reactable-data')[0];
for (var i = 0; i < problem_table.childElementCount; i++) {
    var problem = new Object();
    var tr = problem_table.children[i];
    problem.id = tr.querySelector('td:nth-child(2)').innerText;
    problem.title = tr.querySelector('div > a').innerText;
    problem.href = tr.querySelector('div > a').href;
    problem.difficulty = tr.querySelector('span.label.round').innerText;

    var blog = getBlogById(problem.id);
    if (blog != null) {
        problem.blog_title = blog.title;
        problem.blog_link = blog.href;
    }


    problems.push(problem);
}

var md = "";

for (var i = 0; i < problems.length; i++) {
    var line = "|" + problems[i].id
        + "|" + "[" + problems[i].title + "](" + problems[i].href + ")"
        + "|" + problems[i].difficulty
        + "|" + "[" + problems[i].id + ".cpp" + "](" + "src/" + problems[i].id + ".cpp)"
        + "||";
    md += line;
    md += "\n";
}


function writeFile(filepath, text) {

}

