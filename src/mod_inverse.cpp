import math
from collections import Counter

# --- PHẦN 1: TÍNH ENTROPY ---
def calculate_entropy(data):
    """
    Tính Entropy của một chuỗi dữ liệu.
    Công thức: H(X) = -Σ p(x) * log2(p(x))
    """
    if not data:
        return 0.0
    
    # Đếm số lần xuất hiện của mỗi ký tự
    counts = Counter(data)
    total_chars = len(data)
    
    entropy = 0.0
    for char in counts:
        p_x = counts[char] / total_chars
        entropy -= p_x * math.log2(p_x)
    
    # Làm tròn 4 chữ số thập phân để khớp với Autograder
    return round(entropy, 4)

# --- PHẦN 2: TÌM NGHỊCH ĐẢO MODULO ---
def extended_gcd(a, b):
    """Thuật toán Euclid mở rộng để tìm gcd và hệ số x, y"""
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def mod_inverse(a, m):
    """Tìm x sao cho (a * x) % m == 1"""
    gcd, x, y = extended_gcd(a, m)
    if gcd != 1:
        # Nếu gcd != 1 thì không tồn tại nghịch đảo
        return None 
    else:
        # Đảm bảo kết quả dương trong khoảng [0, m-1]
        return (x % m + m) % m

# --- PHẦN 3: ĐIỀU KHIỂN CHƯƠNG TRÌNH ---
if __name__ == "__main__":
    # Test Entropy
    test_inputs = ["aaaa", "abcd", "hello world"]
    print("--- Kết quả Entropy ---")
    for inp in test_inputs:
        print(f"Input: '{inp}' => Entropy: {calculate_entropy(inp)}")

    print("\n--- Kết quả Modulo Inverse ---")
    # Test Modulo Inverse
    test_cases = [(3, 7), (10, 17), (6, 9)]
    for a, m in test_cases:
        res = mod_inverse(a, m)
        if res is not None:
            print(f"Nghịch đảo của {a} mod {m} là: {res}")
        else:
            print(f"Nghịch đảo của {a} mod {m}: Không tồn tại (gcd != 1)")