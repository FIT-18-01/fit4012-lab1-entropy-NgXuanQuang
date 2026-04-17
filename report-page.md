# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu

Bài lab nhằm giúp sinh viên hiểu và cài đặt các khái niệm cơ bản trong lý thuyết thông tin và số học, bao gồm:

- Tính entropy của chuỗi ký tự để đo mức độ ngẫu nhiên.
- Tính độ dư thừa thông tin (redundancy).
- Tìm nghịch đảo modulo bằng thuật toán Euclid mở rộng.
- Làm quen với việc tổ chức code và quản lý project bằng GitHub.

## 2. Cách làm

- Đọc và hiểu chương trình mẫu tính entropy.
- Sử dụng tần suất xuất hiện của ký tự để tính xác suất.
- Áp dụng công thức để tính entropy.
- Xây dựng thêm hàm tính redundancy dựa trên entropy cực đại.
- Cài đặt thuật toán Euclid mở rộng để tìm modular inverse.
- Kiểm thử chương trình với nhiều bộ test khác nhau.

## 3. Kết quả chính

### 3.1 Entropy và redundancy

| Input       | Entropy | Redundancy | Nhận xét                                     |
| ----------- | ------: | ---------: | -------------------------------------------- |
| aaaa        |   0.000 |      1.000 | Chuỗi không có thông tin (lặp lại hoàn toàn) |
| abcd        |   2.000 |      0.000 | Phân bố đều → entropy tối đa                 |
| hello world |   2.845 |      0.178 | Có lặp ký tự → entropy giảm                  |

### 3.2 Modulo inverse

|   a |   m | Kết quả mong đợi | Kết quả chương trình |
| --: | --: | ---------------- | -------------------- |
|   3 |   7 | 5                | 5                    |
|  10 |  17 | 12               | 12                   |
|   6 |   9 | Không tồn tại    | Không tồn tại        |

## 4. Kết luận

Qua bài lab, em hiểu rõ hơn về cách đo lượng thông tin của một chuỗi thông qua entropy và ý nghĩa của độ dư thừa. Ngoài ra, việc cài đặt thuật toán Euclid mở rộng giúp em hiểu sâu hơn về toán học phía sau bài toán nghịch đảo modulo. Khó khăn lớn nhất là hiểu cách hoạt động của thuật toán Euclid mở rộng, nhưng sau khi chạy thử từng bước và kiểm tra kết quả, em đã nắm được cách tính. Bài lab giúp em kết nối giữa lý thuyết và thực hành một cách rõ ràng hơn.
