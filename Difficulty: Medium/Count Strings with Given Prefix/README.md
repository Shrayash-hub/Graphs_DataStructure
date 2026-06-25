<h2><a href="https://www.geeksforgeeks.org/problems/count-strings-with-given-prefix/1">Count Strings with Given Prefix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array of strings <strong>s[]</strong> and an array of query strings <strong>q[]</strong>, where all strings consist of lowercase English letters. For each query string q[i], find the number of strings in s[] that have q[i] as a <strong>prefix</strong>.</span></p>
<p><span style="font-size: 18px;">Return an array res[] such that res[i] denotes the number of strings in s[] that have prefix q[i].</span></p>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s[] = ["abracadabra", "geeksforgeeks", "abracadabra", "geeks", "geeksthrill"]
q[] = ["abr", "geeks", "ge", "gar"]</span>
<span style="font-size: 18px;"><strong>Output:</strong> [2, 3, 3, 0]</span>
<span style="font-size: 18px;"><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">For each query:</span><strong style="font-size: 18px;">  </strong><span style="font-size: 18px;">
"abr" is a prefix of both occurrences of "<strong>abr</strong>acadabra", so the count is <strong>2</strong>.
"geeks" is a prefix of "<strong>geeks</strong>forgeeks", "<strong>geeks</strong>", and "<strong>geeks</strong>thrill", so the count is <strong>3</strong>.
"ge" is a prefix of "<strong>ge</strong>eksforgeeks", "<strong>ge</strong>eks", and "<strong>ge</strong>eksthrill", so the count is <strong>3</strong>.
"gar" is <strong>not</strong> a prefix of any string in s[], so the count is <strong>0</strong>.</span></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> s[] = ["apple", "app", "banana", "application"]
q[] = ["ap", "ban"]
<strong>Output: </strong>[3, 1]
<strong>Explanation: </strong>For each query: 
"ap" is a prefix of "<strong>ap</strong>ple", "<strong>ap</strong>p", and "<strong>ap</strong>plication", so the count is 3.
"ban" is a prefix of "<strong>ban</strong>ana", so the count is 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ s.size() ≤ 10<sup>4</sup><br>1 ≤ q.size() ≤ 10<sup>4</sup><br>1 ≤ |s[i]|, |q[i]| ≤ 100 &nbsp;</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Tree</code>&nbsp;<code>Trie</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;