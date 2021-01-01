const tryAllPossibilities = (nums, idx, canTake, memo) => {
  if (idx >= nums.length) {
    return 0;
  }
  if (memo[idx][canTake] !== -1) return memo[idx][canTake];
  if (canTake === 1) {
    let a = nums[idx] + tryAllPossibilities(nums, idx + 1, 0, memo);
    let b = tryAllPossibilities(nums, idx + 1, 1, memo);
    return memo[idx][canTake] = Math.max(a, b);
  } else {
    return memo[idx][canTake] = tryAllPossibilities(nums, idx + 1, 1, memo);
  }
};

/**
 * @param {number[]} nums
 * @return {number}
*/
const rob = (nums) => {
  if (nums.length == 0) return 0;
  let memo = Array(nums.length + 2).fill().map(() => Array(2).fill(-1));
  // console.log(`memo: ${JSON.stringify(memo)}`);
  let a = tryAllPossibilities(nums, 0, 1, memo);
  let b = tryAllPossibilities(nums, 0, 0, memo);
  // console.log(`memo: ${JSON.stringify(memo)}`);
  return Math.max(a, b);
};

const main = () => {
  let tests = [
    {
      "nums": [1, 2, 3, 1],
      "expected": 4
    },
    {
      "nums": [0, 2, 3, 2],
      "expected": 4
    },
    {
      "nums": [1, 5, 3, 1],
      "expected": 6
    },
    {
      "nums": [2, 7, 9, 3, 1],
      "expected": 12
    },
    {
      "nums": [2],
      "expected": 2
    },
    {
      "nums": [2, 7],
      "expected": 7
    },
    {
      "nums": [],
      "expected": 0
    },
    {
      "nums": [2, 1, 1, 2],
      "expected": 4
    },
    {
      "nums": [12, 10, 0, 0],
      "expected": 12
    },
    {
      "nums": [183, 219, 57, 193, 94, 233, 202, 154, 65, 240, 97, 234, 100, 249, 186, 66, 90, 238, 168, 128, 177, 235, 50, 81, 185, 165, 217, 207, 88, 80, 112, 78, 135, 62, 228, 247, 211],
      "expected": 3365
    }
  ];

  let succeed = true;
  for (let test of tests) {
    let out = rob(test.nums);
    if (out !== test.expected) {
      console.log(`Failed on test: ${JSON.stringify(test)}, got: ${out}`);
      succeed = false;
    }
  }

  if (succeed) console.log("All tests passed");
  else console.log("Not all tests passed");
};

main();