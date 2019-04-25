/**
 * get finished problem's # and title
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
    problems.push(problem);
}

var md = "";

for (var i = 0; i < problems.length; i++) {
    var line = "|" + problems[i].id
        + "|" + "[" + problems[i].title + "](" + problems[i].href + ")"
        + "|" + problems[i].difficulty
        + "|" + "[" + problems[i].id + ".cpp" + "](" + ".src/" + problems[i].id + ".cpp)" + "||";
    md += line;
    md += "\n";
}

