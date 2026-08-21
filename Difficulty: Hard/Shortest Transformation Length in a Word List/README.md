<h2><a href="https://www.geeksforgeeks.org/problems/word-ladder/1">Shortest Transformation Length in a Word List</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two distinct words <strong>s</strong> and <strong>e</strong>, and a list of unique words <strong>words[]</strong>, where all words have the same length, find the length of the <strong>shortest</strong> transformation sequences from start to end.</span></p>
<p><span style="font-size: 18px;">A valid transformation sequence must satisfy the following conditions:</span></p>
<ul>
<li><span style="font-size: 18px;">Only <strong>one</strong> character can be changed in each transformation.</span></li>
<li><span style="font-size: 18px;">Every transformed word must exist in words[], including e.</span></li>
<li><span style="font-size: 18px;">All words consist only of lowercase English letters.</span></li>
<li><span style="font-size: 18px;"><strong>s</strong>&nbsp;may or may not be present in <strong>words[]</strong>.</span></li>
</ul>
<p><span style="font-size: 18px;">Return the length of the shortest transformation sequence from s to e. If no such sequence exists, return<strong> 0</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>words[] = ["des", "der", "dfr", "dgt", "dfs"], s = "der", e = "dfs"
<strong>Output: </strong>3
<strong>Explanation: </strong>The length of the shortest transformation sequence from "der" to "dfs" is 3 i.e "der" -&gt; "d<strong>f</strong>r" -&gt; "df<strong>s</strong>".
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>words = ["geek", "gefk"], s = "gedk", e = "geek", 
<strong>Output: </strong>2
<strong>Explanation: </strong>The length of the </span><span style="font-size: 14pt;">shortest</span><span style="font-size: 14pt;"> transformation sequence from "gedk" to "geek" is 2 i.e "gedk" -&gt; "ge<strong>e</strong>k"</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>words[] = ["poon", "plee", "same", "poie", "plea", "plie", "poin"], s = "toon", e = "plea",
<strong>Output: </strong>7 
<strong>Explanation: </strong>The length of the </span><span style="font-size: 14pt;">shortest</span><span style="font-size: 14pt;"> transformation sequence from "toon" to "plea" is 7 i.e<strong>., </strong>toon -&gt; <strong>p</strong>oon -&gt; po<strong>i</strong>n -&gt; poi<strong>e</strong> -&gt; p<strong>l</strong>ie -&gt; pl<strong>e</strong>e -&gt; ple<strong>a </strong></span></pre>
<p><span style="font-size: 18px;"><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br><span style="font-size: 14pt;">1 ≤ n ≤ 5 * 10<sup>3</sup>, where n is the length of words</span><br><span style="font-size: 14pt;">1 ≤ m ≤ 10, where m is the length </span>of words[i]</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>BFS</code>&nbsp;