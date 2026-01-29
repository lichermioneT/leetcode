# LeetCode

## 611

给定一个包含非负整数的数组 `nums` ，返回其中可以组成三角形三条边的三元组个数。

**示例 1:**

```
输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
```

**示例 2:**

```
输入: nums = [4,2,3,4]
输出: 4
```

**总结**

 0  1  2  3  4  5  6

 [2, 2, 3, 4, 5, 9, 10]

 2+9已经大于10了，左边单调递增的，所以这区间的全部符合。right--

2+5已经小于10了，右边单调递减的，所以需要区间变大。letf++

然后重复

**c++版本**

```c++
class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        // 任意 a + b > c;
        // 这里可以计算重复的
        // a<=b<=c -- 这里只需要判断 a+b>c。c无论加上a,b都是大的。
        // 优化先对数据进行排序
        /*
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    for(k = 0; k < n; k++)
                        check(i, j k)     3 * n3  nlogn + n3
            0   1  2  3  4  5   6
            [2, 2, 3, 4, 5, 9, 10]
             2+9 > 10 已经大于10现在只需要 right--; right-left种方法
             2+5 < 10 已经小于10现在只需要 left++;
             letf==right时 10--。
        
        1.固定最大的数
        2.最大数左边区间，双指针计算
        3.
        */

        sort(nums.begin(), nums.end());
        
        int ret = 0; 
        int n = nums.size();
        for(int i = n - 1; i >= 2; i--)
        {
            // 双指针统计
            int left = 0;
            int right = i - 1;
            while(left < right)
            {
                if(nums[right] + nums[left] > nums[i])
                {
                    ret += right - left;
                    right--;
                }
                else 
                {
                    left++;
                }
            }
        }
        return ret;
    }
};
```



**c语言版本**

```c
int triangleNumber(int* nums, int numsSize) 
{

    for(int i = 0; i < numsSize - 1; i++)
    {
        
        for(int j = 0; j < numsSize - 1 - i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }


    int ret = 0;
    for(int i = numsSize - 1; i >=2; i--)
    {
        int left = 0;
        int right = i-1;
        
        while(left < right)
        {
            if(nums[left] + nums[right] > nums[i])
            {
                ret += right-left;
                right--;
            }
            else 
            {
                left++;
            }
        }
    }

    return ret;
}
```



## 1089

**给你一个长度固定的整数数组 `arr` ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。**

**注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。**

**示例 1：**

```
输入：arr = [1,0,2,3,0,4,5,0]
输出：[1,0,0,2,3,0,0,4]
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
```

**示例 2：**

```
输入：arr = [1,2,3]
输出：[1,2,3]
解释：调用函数后，输入的数组将被修改为：[1,2,3]

```

**总结：先找到最后一个复写的元素。**

**可能复写的最后元素可能是零，所以需要单独处理一下**

**不是零的直接进行处理就行。**



**c++实现版本**

```c++
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int sz = arr.size();
        int cur = 0;
        int i = 0;
        while(cur < sz)
        {
            if(arr[i]  == 0)
            {
                cur += 2;
            }
            else 
            {
                cur += 1;
            }
            i++;
        }

        i--;
        int index = sz-1;
        
        if(cur > sz)
        {
            arr[index--] = 0;
            i--;
        }

        while(i > 0)
        {
            if(arr[i] == 0)
            {
                arr[index--] = 0;
                arr[index--] = 0;
            }
            else 
            {
                arr[index--] = arr[i];
            }
            i--;
        }

        // int n = arr.size();
        // int cur = 0;  // 判断满了没得
        // int i = 0;   // 需要复写的最后一个元素。

        // // 1. 找到最后一个会被处理的元素
        // while (cur < n) 
        // {
        //     if (arr[i] == 0) cur += 2;
        //     else cur += 1;
        //     i++;
        // }

        // i--;                // 最后一个有效原数组元素
        // int index = n - 1;  // 实际写入位置

        // // 2. 处理“多出来的 0”
        // if (cur > n) 
        // {      // 说明最后是 0，只能写一个
        //     arr[index] = 0;
        //     index--;
        //     i--;
        // }

        // // 3. 从后往前写
        // while (i >= 0) 
        // {
        //     if (arr[i] == 0) 
        //     {
        //         arr[index--] = 0;
        //         arr[index--] = 0;
        //     } 
        //     else 
        //     {
        //         arr[index--] = arr[i];
        //     }
        //     i--;
        // }

    }
};

```



## 202

编写一个算法来判断一个数 `n` 是不是快乐数。

**「快乐数」** 定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果这个过程 **结果为** 1，那么这个数就是快乐数。

如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。

**示例 1：**

```
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**示例 2：**

```
输入：n = 2
输出：false
```



**c++实现版本**

```c++
class Solution {
public:
//     bool isHappy(int n) 
//     {   
        
//         int slow = n;
//         int fast = bitSum(n);
//         while(slow != fast)
//         {
//             slow = bitSum(slow);
//             fast = bitSum(bitSum(fast));
//         }

//         return fast == 1;
//     }


// private:
//     int bitSum(int n)
//     {
//         int sum = 0;
//         while(n > 0)
//         {
//             int t = n % 10; // 取0-9;
//             sum += t * t;
//             n /= 10;        // 删除一位 
//         }
//         return sum;
//     }

bool isHappy(int n)
{
    int slow = n;
    int fast = bitSum(n);
    while(slow != fast)
    {
        slow = bitSum(slow);
        fast = bitSum(bitSum(fast));
    }
    return fast == 1;
}

private:
    int bitSum(int n)
    {
        int sum = 0;
        while(n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
};
```



## 26

给你一个 **非严格递增排列** 的数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k`。去重后，返回唯一元素的数量 `k`。

`nums` 的前 `k` 个元素应包含 **排序后** 的唯一数字。下标 `k - 1` 之后的剩余元素可以忽略。

**判题标准:**

系统会用下面的代码来测试你的题解:

```
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被 **通过**。

**示例 1：**

```
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4,_,_,_,_,_]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

```



**c++实现版本**

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // if(nums.empty())
        //     return 0;

        // int index = 0;                 // 记录数组中不重复的元素
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[index] != nums[i])
        //     {
        //         nums[++index] = nums[i];
        //     }
        // }    

        // return index+1;


        if(nums.empty())
            return 0;

        int index = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[index] != nums[i])
            {
                nums[++index] = nums[i];
            }
        }

        return index+1;
    }
};
```



## 66

给定一个表示 **大整数** 的整数数组 `digits`，其中 `digits[i]` 是整数的第 `i` 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 `0`。

将大整数加 1，并返回结果的数字数组。

**示例 1：**

```
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
加 1 后得到 123 + 1 = 124。
因此，结果应该是 [1,2,4]。
```

**示例 2：**

```
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
加 1 后得到 4321 + 1 = 4322。
因此，结果应该是 [4,3,2,2]。
```

**示例 3：**

```
输入：digits = [9]
输出：[1,0]
解释：输入数组表示数字 9。
加 1 得到了 9 + 1 = 10。
因此，结果应该是 [1,0]。
```





```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // 从最后一位开始加1
        for (int i = n - 1; i >= 0; i--) 
        {
            digits[i]++;  // 当前位加1
            
            if (digits[i] < 10) 
            {
                return digits;  // 没有进位，直接返回
            }
            
            digits[i] = 0;  // 当前位变成0，进位到前一位
        }
        
        // 如果循环结束还没返回，说明最高位也进位了
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```





























































