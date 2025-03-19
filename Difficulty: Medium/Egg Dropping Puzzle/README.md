<h2><a href="https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?page=1&company=Service%20Now&sortBy=submissions">Egg Dropping Puzzle</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">You are given <strong>n </strong>identical eggs and you have access to a<strong> k</strong>-floored building from&nbsp;<strong>1</strong> to <strong>k.</strong></span></p>
<p><span style="font-size: 14pt;">There exists a floor <strong>f</strong> where <strong>0</strong> &lt;= <strong>f</strong> &lt;= <strong>k </strong>such that any egg dropped from a floor higher than <strong>f</strong>&nbsp;will break, and any egg dropped <strong>from or below </strong>floor f<strong>&nbsp;</strong>will <strong>not break</strong>. <br>There are few rules given below.&nbsp;</span></p>
<ul>
<li><span style="font-size: 14pt;">An egg that survives a fall can be used again.</span></li>
<li><span style="font-size: 14pt;">A broken egg must be discarded.</span></li>
<li><span style="font-size: 14pt;">The effect of a fall is the same for all eggs.</span></li>
<li><span style="font-size: 14pt;">If the egg doesn't break at a certain floor, it will not break at any floor below.</span></li>
<li><span style="font-size: 14pt;">If the egg breaks on a certain floor, it will break on any floor above.</span></li>
</ul>
<p><span style="font-size: 14pt;">Return the minimum number of moves&nbsp;<span style="box-sizing: border-box; margin: 0px; padding: 0px;">you need to determine the value of&nbsp;<strong>f</strong> with certainty</span>.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> n<strong> </strong>= 1<strong>, </strong>k<strong> </strong>= 2
<strong>Output: </strong>2
<strong>Explanation: </strong>Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2.If it breaks, we know that f = 1.  If it does not break, then we know f = 2. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> n<strong> </strong>= 10<strong>, </strong>k<strong> </strong>= 5
<strong>Output: </strong>3
<strong>Explanation: </strong>Drop the egg from floor 2. If it breaks, test floor 1 with a remaining egg.If it doesn’t break, drop from floor 4. If it breaks, test floor 3. If it still doesn’t break, we know the critical floor is 5.Hence, with a minimum of 3 moves, we can find the critical floor.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> n<strong> </strong>= 2<strong>, </strong>k<strong> </strong>= 10
<strong>Output: </strong>4
<strong>Explanation: </strong>Drop the egg from floor 4. If it breaks, we only need to test floors 1 to 3 with the remaining egg.If it doesn't break, drop the egg from floor 7. If it breaks, we only need to test floors 5 and 6. If it doesn't break again, drop the egg from floor 9. If it breaks, test floor 8. If it still doesn’t break, we know the critical floor is 10.Hence, with a minimum of 4 moves, we can determine the critical floor.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1&lt;= n &lt;=100<br>1&lt;= k &lt;=100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>VMWare</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>Hike</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Oracle</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>MAQ Software</code>&nbsp;<code>Google</code>&nbsp;<code>Myntra</code>&nbsp;<code>nearbuy</code>&nbsp;<code>Opera</code>&nbsp;<code>Philips</code>&nbsp;<code>Service Now</code>&nbsp;<code>Unisys</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;