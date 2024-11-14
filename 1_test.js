const fs = require("fs");

const data = fs.readFileSync(0, "utf-8").trim().split("\n");

const [n, x] = data[0].split(" ").map(Number);

const a = data[1].split(" ").map(Number);

a.sort((x, y) => x - y);

let l = 0,
  r = n - 1;

let ans = 0;

while (l <= r) {
  if (a[l] + a[r] <= x) {
    ans++;
    l++, r--;
  } else {
    r--;
    ans++;
  }
}

console.log(ans);
