<h2><a href="https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">3</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="hsla(216,60%,60%,1)" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1373. Maximum Sum BST in Binary Tree</a></h2><h3>Hard</h3><hr><div><p>Given a <strong>binary tree</strong> <code>root</code>, return <em>the maximum sum of all keys of <strong>any</strong> sub-tree which is also a Binary Search Tree (BST)</em>.</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png" style="width: 320px; height: 250px;"></p>

<pre><strong>Input:</strong> root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
<strong>Output:</strong> 20
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png" style="width: 134px; height: 180px;"></p>

<pre><strong>Input:</strong> root = [4,3,null,1,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [-4,-2,-5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All values are negatives. Return an empty BST.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 4 * 10<sup>4</sup>]</code>.</li>
	<li><code>-4 * 10<sup>4</sup> &lt;= Node.val &lt;= 4 * 10<sup>4</sup></code></li>
</ul>
</div>