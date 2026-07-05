# ============================================================
# ĐỀ TÀI 2 - PHÂN TÍCH ĐIỂM SỐ HỌC SINH
# File: hd1.R
# Dữ liệu: diem_so.csv
# ============================================================

# 1. CÀI ĐẶT VÀ KHỞI TẠO THƯ VIỆN
install.packages("tidyverse")
install.packages("summarytools")
install.packages("visdat")

library(tidyverse)
library(summarytools)
library(visdat)

# ============================================================
# 2. ĐỌC DỮ LIỆU (Import Data)
# ============================================================
data_raw <- read.csv("diem_so.csv")
# doc du lieu tu file diem_so.csv
# Chọn các cột cần thiết theo đề bài
data <- data_raw[, c("G1", "G2", "G3", "studytime", "failures", "absences", "paid", "sex")]

# ============================================================
# 3. LÀM SẠCH DỮ LIỆU (Data Cleaning)
# ============================================================
# Kiểm tra giá trị NA
apply(is.na(data), 2, sum)

# Loại bỏ dòng có NA
data <- na.omit(data)

# Lọc bỏ các dòng có điểm G3 âm (vô lý trong thực tế)
data <- data[data$G1 >= 0, ]
data <- data[data$G2 >= 0, ]
data <- data[data$G3 >= 0, ]
# ============================================================
# 4. CHUYỂN ĐỔI BIẾN (Convert Variables)
# ============================================================
# failures: biến thứ bậc, chỉ nhận giá trị nguyên cố định (0,1,2,3,4)
# => chuyển thành factor là hợp lý
data$sex <- as.factor(data$sex)
data$paid <- as.factor(data$paid)
data$studytime <- as.factor(data$studytime)
data$failures <- as.factor(data$failures)

View(data)
# ============================================================
# 5. THỐNG KÊ MÔ TẢ (Descriptive Statistics)
# ============================================================

# --- 5a. Tổng quan toàn bộ bảng dữ liệu ---
cat("\n", rep("=", 50), "\n", sep = "")
cat("TỔNG QUAN DỮ LIỆU (summary):\n")
print(summary(data))

# --- 5b. Thống kê chi tiết các biến số liên tục ---
# failures đã là factor nên chỉ thống kê số học cho: G1, G2, G3, absences
cols_numeric <- c("G1", "G2", "G3", "absences")

for (col in cols_numeric) {
    x <- data[[col]]
    cat("\n", rep("=", 50), "\n", sep = "")
    cat("PHÂN TÍCH BIẾN:", toupper(col), "\n")
    cat(" - Trung bình (mean):      ", round(mean(x), 2), "\n")
    cat(" - Trung vị (median):      ", round(median(x), 2), "\n")
    cat(" - Độ lệch chuẩn (sd):     ", round(sd(x), 2), "\n")
    cat(" - Phương sai (var):       ", round(var(x), 2), "\n")
    cat(" - Giá trị nhỏ nhất (min): ", min(x), "\n")
    cat(" - Giá trị lớn nhất (max): ", max(x), "\n")
}

# --- 5c. Bảng tần số các biến phân loại ---
cat("\n---- Tần số và tỷ lệ: Giới tính (sex) ----\n")
print(table(data$sex))
print(prop.table(table(data$sex)))

cat("\n---- Tần số và tỷ lệ: Học thêm (paid) ----\n")
print(table(data$paid))
print(prop.table(table(data$paid)))

cat("\n---- Tần số và tỷ lệ: Thời gian tự học (studytime) ----\n")
print(table(data$studytime))
print(prop.table(table(data$studytime)))

cat("\n---- Tần số và tỷ lệ: Số lần trượt môn (failures) ----\n")
print(table(data$failures))
print(prop.table(table(data$failures)))

# ============================================================
# 6. TRỰC QUAN HÓA DỮ LIỆU (Data Visualization)
# ============================================================
if (!dir.exists("plots")) dir.create("plots")

# --- Histogram: G1, G2, G3 (so sánh phân phối 3 biến điểm) ---
png("plots/plot1_istogram_G1_G2_G3.png", width = 900, height = 400)
par(mfrow = c(1, 3))
hist(data$G1,
    main = "Phân phối Điểm HK1 (G1)",
    xlab = "G1", col = "salmon", border = "white"
)
hist(data$G2,
    main = "Phân phối Điểm HK2 (G2)",
    xlab = "G2", col = "gold", border = "white"
)
hist(data$G3,
    main = "Phân phối Điểm Cuối Kỳ (G3)",
    xlab = "G3", col = "skyblue", border = "white"
)
par(mfrow = c(1, 1))
dev.off()

# --- Histogram: Absences ---
png("plots/plot2_histogram_absences.png", width = 600, height = 400)
hist(data$absences,
    main = "Phân phối Số ngày nghỉ (absences)",
    xlab = "Absences", col = "mediumpurple", border = "white"
)
dev.off()

# --- Barplot: Failures (vì là factor dùng barplot thay histogram) ---
png("plots/plot3_barplot_failures.png", width = 600, height = 400)
barplot(table(data$failures),
    main = "Phân phối Số lần trượt môn (failures)",
    xlab = "Failures", ylab = "Số học sinh",
    col = "tomato"
)
dev.off()

# --- Boxplot: Studytime vs G3 ---
png("plots/plot4_studytime_vs_G3.png", width = 600, height = 400)
boxplot(G3 ~ studytime,
    data = data,
    main = "Thời gian tự học vs Điểm G3",
    xlab = "Studytime", ylab = "Điểm G3",
    col = "orange"
)
dev.off()

# --- Boxplot: Failures vs G3 ---
png("plots/plot5_failures_vs_G3.png", width = 600, height = 400)
boxplot(G3 ~ failures,
    data = data,
    main = "Số lần trượt môn vs Điểm G3",
    xlab = "Failures", ylab = "Điểm G3",
    col = "salmon"
)
dev.off()

# --- Boxplot: Paid vs G3 ---
png("plots/plot6_paid_vs_G3.png", width = 600, height = 400)
boxplot(G3 ~ paid,
    data = data,
    main = "Học thêm (paid) vs Điểm G3",
    xlab = "Paid", ylab = "Điểm G3",
    col = "lightgreen"
)
dev.off()

# --- Boxplot: Sex vs G3 ---
png("plots/plot7_sex_vs_G3.png", width = 600, height = 400)
boxplot(G3 ~ sex,
    data = data,
    main = "Giới tính vs Điểm G3",
    xlab = "Sex", ylab = "Điểm G3",
    col = "plum"
)
dev.off()

# --- Scatter plot: Absences vs G3 ---
png("plots/plot8_absences_vs_G3.png", width = 600, height = 400)
plot(data$absences, data$G3,
    main = "Số ngày nghỉ vs Điểm G3",
    xlab = "Absences", ylab = "Điểm G3",
    col = rgb(0.2, 0.4, 0.6, 0.5), pch = 19
)
abline(lm(G3 ~ absences, data = data), col = "red", lwd = 2)
dev.off()

# --- Scatter plot: G1 vs G3 ---
png("plots/plot9_G1_vs_G3.png", width = 600, height = 400)
plot(data$G1, data$G3,
    main = "Điểm HK1 (G1) vs Điểm cuối kỳ (G3)",
    xlab = "G1", ylab = "G3",
    col = rgb(0.2, 0.4, 0.6, 0.5), pch = 19
)
abline(lm(G3 ~ G1, data = data), col = "red", lwd = 2)
dev.off()

# --- Scatter plot: G2 vs G3 ---
png("plots/plot10_G2_vs_G3.png", width = 600, height = 400)
plot(data$G2, data$G3,
    main = "Điểm HK2 (G2) vs Điểm cuối kỳ (G3)",
    xlab = "G2", ylab = "G3",
    col = rgb(0.8, 0.4, 0, 0.5), pch = 19
)
abline(lm(G3 ~ G2, data = data), col = "blue", lwd = 2)
dev.off()

# ============================================================
# 7. HỒI QUY TUYẾN TÍNH
# ============================================================
model_BTL <- lm(G3 ~ G1 + G2 + studytime + failures + absences + paid + sex,
    data = data
)

cat("\n", rep("=", 50), "\n", sep = "")
cat("KẾT QUẢ MÔ HÌNH HỒI QUY TUYẾN TÍNH:\n")
print(summary(model_BTL))

# ============================================================
# 8. DỰ BÁO ĐIỂM HỌC SINH MỚI (Prediction)
# ============================================================
# Thông tin học sinh: G1=10, G2=11, studytime=3,
# failures=0, absences=2, paid="yes", sex="F"
new_student <- data.frame(
    G1        = 10,
    G2        = 11,
    studytime = factor(3, levels = levels(data$studytime)),
    failures  = factor(0, levels = levels(data$failures)),
    absences  = 2,
    paid      = factor("yes", levels = levels(data$paid)),
    sex       = factor("F", levels = levels(data$sex))
)

prediction <- predict(model_BTL, newdata = new_student)

cat("\n", rep("=", 50), "\n", sep = "")
cat("DỰ BÁO ĐIỂM CUỐI KỲ (G3):\n")
cat("Điểm G3 dự báo:", round(prediction, 2), "\n")
cat("\n")
cat("\n")
cat("\n")

# Biểu đồ so sánh điểm thực tế vs dự báo
png("plots/plot11_actual_vs_predicted.png", width = 600, height = 400)
predicted_values <- predict(model_BTL)
actual_values <- data$G3
plot(actual_values, predicted_values,
    main = "So sánh: Điểm thực tế vs Điểm dự báo",
    xlab = "Điểm G3 thực tế",
    ylab = "Điểm G3 dự báo",
    col = rgb(0.2, 0.5, 0.8, 0.3), pch = 19
)
abline(0, 1, col = "red", lwd = 2)
dev.off()
