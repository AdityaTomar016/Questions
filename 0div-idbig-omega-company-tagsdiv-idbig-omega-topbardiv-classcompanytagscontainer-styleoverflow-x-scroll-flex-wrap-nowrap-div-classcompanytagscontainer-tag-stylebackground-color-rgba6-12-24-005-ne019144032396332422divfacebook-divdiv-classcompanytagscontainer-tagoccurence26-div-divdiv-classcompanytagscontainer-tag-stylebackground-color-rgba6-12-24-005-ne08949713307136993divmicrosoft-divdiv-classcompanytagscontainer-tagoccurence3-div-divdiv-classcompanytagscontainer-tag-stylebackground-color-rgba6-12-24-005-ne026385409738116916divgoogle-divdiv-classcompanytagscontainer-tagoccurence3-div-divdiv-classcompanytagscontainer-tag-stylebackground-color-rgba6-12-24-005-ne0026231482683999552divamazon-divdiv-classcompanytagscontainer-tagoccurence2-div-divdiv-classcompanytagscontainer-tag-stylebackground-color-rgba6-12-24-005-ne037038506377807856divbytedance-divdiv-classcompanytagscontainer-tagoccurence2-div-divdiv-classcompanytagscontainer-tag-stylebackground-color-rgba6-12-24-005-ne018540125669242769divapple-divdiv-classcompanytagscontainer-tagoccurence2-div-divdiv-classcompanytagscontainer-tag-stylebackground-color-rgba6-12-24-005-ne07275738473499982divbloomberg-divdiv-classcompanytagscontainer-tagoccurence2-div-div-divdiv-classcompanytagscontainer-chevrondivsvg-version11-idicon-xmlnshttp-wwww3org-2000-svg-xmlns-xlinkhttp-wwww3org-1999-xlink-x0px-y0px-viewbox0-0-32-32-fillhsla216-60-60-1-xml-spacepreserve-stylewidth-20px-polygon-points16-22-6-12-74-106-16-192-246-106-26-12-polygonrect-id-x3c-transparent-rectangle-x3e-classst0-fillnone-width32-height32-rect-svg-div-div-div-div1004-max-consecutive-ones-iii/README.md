<h2><a href="https://leetcode.com/problems/max-consecutive-ones-iii/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.19144032396332422"><div>Facebook</div><div class="companyTagsContainer--tagOccurence">26</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.8949713307136993"><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.26385409738116916"><div>Google</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.026231482683999552"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.37038506377807856"><div>ByteDance</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.18540125669242769"><div>Apple</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.7275738473499982"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="hsla(216,60%,60%,1)" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1004. Max Consecutive Ones III</a></h2><h3>Medium</h3><hr><div><p>Given a binary array <code>nums</code> and an integer <code>k</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array if you can flip at most</em> <code>k</code> <code>0</code>'s.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> [1,1,1,0,0,<u><strong>1</strong>,1,1,1,1,<strong>1</strong></u>]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
<strong>Output:</strong> 10
<strong>Explanation:</strong> [0,0,<u>1,1,<strong>1</strong>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1</u>,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>
</div>