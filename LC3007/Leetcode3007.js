/**
 * @param {number} k
 * @param {number} x
 * @return {number}
 */
var findMaximumNumber = function (k, x) {
  function countAccumulatedPrice(num) {
    let d = 0;
    let numStr = num.toString(2);
    let pbi = new Array();
    populateArray(pbi, num);
    let t = 0;
    let n = 1;
    for (let i = numStr.length - 1; i >= 0; i--) {
      if (numStr[i] == "1") {
        t += n;
      }
      pbi.unshift(t);
      n *= 2;
    }
    for (let i = 0; i < numStr.length; i++) {
      if ((numStr.length - i) % x != 0) {
        continue;
      }
      let tnum = 0;
      if (numStr[i] == "1") {
        if (i + 1 < pbi.length) {
          tnum += pbi[i + 1] + 1;
        } else {
          tnum++;
        }
      }
      tnum += Math.floor((num - pbi[i]) / 2);
      d += tnum;
    }
    if (d > k) {
      return false;
    } else {
      return true;
    }
  }
  let max = k ** x;
  let max2 = 2 ** x * k * 10;
  if (max2 > max) {
    max = max2;
  }
  let min = 1;
  if (countAccumulatedPrice(max) == true) {
    return max;
  }
  if (countAccumulatedPrice(min + 1) == false) {
    return min;
  }
  let c = {};
  let l = min;
  let h = max;
  let m = Math.floor((l + h) / 2);
  while (l <= h) {
    let v = countAccumulatedPrice(m);
    c[m] = v;
    if (v == true) {
      if (c[m + 1] == false) {
        return m;
      }
      l = m + 1;
    } else if (v == false) {
      if (c[m - 1] == true) {
        return m - 1;
      }
      h = m - 1;
    }
    m = Math.floor((l + h) / 2);
  }
};
