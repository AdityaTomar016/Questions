<h2><a href="https://leetcode.com/problems/3sum/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.551234891679089"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">44</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.20690617567937752"><div>Facebook</div><div class="companyTagsContainer--tagOccurence">28</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.29272353044830157"><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">20</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.9765194095183631"><div>Apple</div><div class="companyTagsContainer--tagOccurence">10</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.04069706493741987"><div>Adobe</div><div class="companyTagsContainer--tagOccurence">9</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.43554217969718345"><div>Google</div><div class="companyTagsContainer--tagOccurence">8</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.11456876632470991"><div>Walmart Global Tech</div><div class="companyTagsContainer--tagOccurence">7</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.23840073457583522"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">6</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.4495361239085647"><div>Uber</div><div class="companyTagsContainer--tagOccurence">6</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.963069524893444"><div>Qualtrics</div><div class="companyTagsContainer--tagOccurence">5</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.4127144721434275"><div>Yahoo</div><div class="companyTagsContainer--tagOccurence">5</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.5025097278561013"><div>Goldman Sachs</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.7884338054962328"><div>tiktok</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.28885221504727765"><div>Salesforce</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.7814433910681999"><div>VMware</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.9522536332809801"><div>ByteDance</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.15767730194761165"><div>Morgan Stanley</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.9839608820618597"><div>Cisco</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.018585543838029794"><div>Oracle</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.629049106588317"><div>Tesla</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.10065218622796568"><div>American Express</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(6, 12, 24, 0.05);" ne="0.7414943003673617"><div>Infosys</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="hsla(216,60%,60%,1)" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>15. 3Sum</a></h2><h3>Medium</h3><hr><div><p>Given an integer array nums, return all the triplets <code>[nums[i], nums[j], nums[k]]</code> such that <code>i != j</code>, <code>i != k</code>, and <code>j != k</code>, and <code>nums[i] + nums[j] + nums[k] == 0</code>.</p>

<p>Notice that the solution set must not contain duplicate triplets.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-1,0,1,2,-1,-4]
<strong>Output:</strong> [[-1,-1,2],[-1,0,1]]
<strong>Explanation:</strong> 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,1]
<strong>Output:</strong> []
<strong>Explanation:</strong> The only possible triplet does not sum up to 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0]
<strong>Output:</strong> [[0,0,0]]
<strong>Explanation:</strong> The only possible triplet sums up to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 3000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>