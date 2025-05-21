<h2><a href="https://www.geeksforgeeks.org/problems/count-the-triplets4615/1">Count the triplets</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><div>
<p class="" data-start="440" data-end="526"><span style="font-size: 14pt;">Given an array <code data-start="455" data-end="460">arr</code>, count the number of <strong data-start="482" data-end="503">distinct triplets</strong> (a, b, c) such that:</span></p>
<ul data-start="531" data-end="766">
<li class="" data-start="531" data-end="544">
<p class="" data-start="533" data-end="544"><span style="font-size: 14pt;">a + b = c</span></p>
</li>
<li class="" data-start="547" data-end="627">
<p class="" data-start="549" data-end="627"><span style="font-size: 14pt;">Each triplet is counted <strong data-start="573" data-end="586">only once</strong>, regardless of the order of <code data-start="615" data-end="618">a</code> and <code data-start="623" data-end="626">b</code>.</span></p>
</li>
<li class="" data-start="630" data-end="764">
<p class="" data-start="632" data-end="764"><span style="font-size: 14pt;">Even if the same number appears multiple times in the array, a valid triplet should be counted <strong data-start="727" data-end="763">only once per unique combination</strong>.</span></p>
</li>
</ul>
</div>
<p><span style="font-size: 14pt;"><strong>Examples:</strong> </span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [1, 5, 3, 2]
<strong>Output:</strong> 2 
<strong>Explanation</strong>: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [2, 3, 4]
<strong>Output:</strong> 0
<strong>Explanation</strong>: No such triplet exits</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>3</sup><br>1 ≤ arr[i] ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Arcesium</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>two-pointer-algorithm</code>&nbsp;<code>Sorting</code>&nbsp;<code>Algorithms</code>&nbsp;