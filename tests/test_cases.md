# Test Cases

## Q1 + Q2 (Entropy & Redundancy)

| #   | Input  | Entropy (Expected) | Redundancy (Expected) | Ghi chú             |
| --- | ------ | -----------------: | --------------------: | ------------------- |
| 1   | AAAA   |              0.000 |                 1.000 | Chuỗi lặp hoàn toàn |
| 2   | ABAB   |              1.000 |                 0.000 | 2 ký tự phân bố đều |
| 3   | ABCD   |              2.000 |                 0.000 | 4 ký tự khác nhau   |
| 4   | AABBBB |              0.918 |                 0.082 | Phân bố không đều   |
| 5   | HELLO  |              1.922 |                 0.039 | Có ký tự lặp        |

---

## Q3 (Modular Inverse)

| #   |   a |   m | Expected Output | Ghi chú            |
| --- | --: | --: | --------------- | ------------------ |
| 1   |   3 |  11 | 4               | 3×4 ≡ 1 (mod 11)   |
| 2   |  10 |  17 | 12              | 10×12 ≡ 1 (mod 17) |
| 3   |   2 |   4 | Không tồn tại   | gcd ≠ 1            |
| 4   |   7 |  26 | 15              | 7×15 ≡ 1 (mod 26)  |
| 5   |   5 |  12 | 5               | 5×5 ≡ 1 (mod 12)   |

---

## Ghi chú

- Entropy tính theo công thức:
  H = -∑ p(x) log₂ p(x)
- Redundancy:
  R = 1 - H / log₂(m)
- Modular inverse chỉ tồn tại khi gcd(a, m) = 1
