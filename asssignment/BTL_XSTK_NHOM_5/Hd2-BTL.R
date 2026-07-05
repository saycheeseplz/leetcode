# Cài đặt thư viện
library(tidyverse)
# =====================================================================
# Phần 1. Đọc dữ liệu và gán tên cột
# =====================================================================
# File machine.data không có header, ta tự định nghĩa dựa trên file machine.names
column_names <- c("VendorName", "ModelName", "MYCT", "MMIN", "MMAX", 
                  "CACH", "CHMIN", "CHMAX", "PRP", "ERP")#tạo một danh sách chứa 10 cái tên và lưu nó vào một biến tên là column_names

# Đọc file CSV
main_data <- read.csv("machine.data", header = FALSE, col.names = column_names)#đọc file, thông báo header hiện tại không phải là dòng chứa tên cột, sau đó gán tên cột bằng colum_names mới tạo
#dùng cho debug: write.csv(main_data, "machine_data_after_convert_&_gotName.csv", row.names = FALSE)

# Kiểm tra dữ liệu khuyết (Sẽ trả về 0 cho tất cả các cột)
print("Số lượng dữ liệu khuyết:")
colSums(is.na(main_data))#đánh dấu các ô có NA bằng true(số 1), sau đó colSums tính tổng tất cả số 1 đó ở mỗi cột và trả về

# Xem 10 dòng đầu tiên của file main_data
head(main_data, 10)



# =====================================================================
# Phần 2. Thống kê
# =====================================================================
# 2.1 Thống kê biến liên tục
cont_cols <- c("MYCT", "MMIN", "MMAX", "CACH", "CHMIN", "CHMAX", "PRP")
#viết hàm tính các đại lượng thống kê
get_summary_stats <- function(df, cols) {#hàm nhận vào df (bảng dữ liệu) và cols (danh sách các cột cần tính)
  data.frame(#tạo bảng excel với từng input là từng cột
    #GTNN duyệt qua bảng dữ liệu df trong vùng cols đã giới hạn theo, duyệt theo từng cột(số 2, trả về kết quả là một hàng gồm các min
    GTNN = apply(df[cols], 2, min),
    Do_lech_chuan = apply(df[cols], 2, sd),
    Trung_binh = apply(df[cols], 2, mean),
    Trung_vi = apply(df[cols], 2, median),
    GTLN = apply(df[cols], 2, max),
    Q1 = apply(df[cols], 2, function(x) quantile(x, 0.25)), #tứ phân vị thứ nhất
    Q3 = apply(df[cols], 2, function(x) quantile(x, 0.75)) #tứ phân vị thứ ba
  )#data.frame chuyển các hàng dữ liệu trên thành cột rồi merge với nhau với cols.name mới là GTNN ,Do_lech_chua,...
}

stats_df <- get_summary_stats(main_data, cont_cols)#gọi hàm với bảng dữ liệu và phần dữ liệu giới hạn


print("Thống kê biến liên tục:")
print(round(stats_df, 2)) #in bảng kết quả sau khi chạy hàm với các giá trị làm tròn 2 chữ số thập phân
#Dùng cho debug: write.csv(round(stats_df, 2), "ket_qua_thong_ke_mo_ta_da_lam_tron.csv", row.names = TRUE)

# 2.2 Thống kê biến rời rạc
print("Số lượng máy tính theo hãng sản xuất (Top 10):")
head(sort(table(main_data$VendorName), decreasing = TRUE), 10)#đọc riêng cột VendorName, phân loại các tên giống nhau và đếm số lượng(bảng tần số), dùng sort+decrease để sắp xếp giảm dần, sau đó hàm head+10 lấy 10 dữ liệu ở đầu bảng (top 10)


# Chuyển đổi dữ liệu sang dạng dài để vẽ biểu đồ cho nhiều biến cùng lúc
main_data_long <- main_data %>% #toán tử pipe, lấy dữ liệu ->đi lọc cột bằng select->lấy kết quả đi gập các cột thành dạng dọc->kết quả gán vào main_data_long
  select(MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX, PRP) %>%
  pivot_longer(cols = c("MYCT", "MMIN", "MMAX", "CACH", "CHMIN", "CHMAX"), 
               names_to = "Variable", 
               values_to = "Value") #chuyển bảng dữ liệu thành bảng chỉ có 3 cột là PRP(giữ nguyên), Variable và value
#dùng cho debug: write.csv(main_data_long, "du_lieu_dang_doc_de_ve_bieu_do.csv", row.names = FALSE)
# =====================================================================
# Phần 3. Vẽ đồ thị biểu diễn
# =====================================================================
# 3.1 ĐỒ THỊ SCATTER: Mối quan hệ giữa PRP và các thông số khác
p_scatter <- ggplot(main_data_long, aes(x = Value, y = PRP)) +
  geom_point(alpha = 0.5, color = "steelblue") + #chỉnh độ trong suốt, màu sắc của điểm
  facet_wrap(~ Variable, scales = "free_x", ncol = 3) + #dấu ngã là chia theo, Variable có 6 biến thì chia 
                                                        #làm 6 đồ thị, free_x giúp scale lại đồ thị cho phù
                                                        #hợp với giá trị của đồ thị đó, xếp 6 đồ thị
                                                        #thành 3 cột ngang, còn trục y là trục cần đối chiếu nên không scale
  theme_minimal() + #tẩy nền xám -> trắng cho dễ nhìn
  labs(title = "Scatter Plot: PRP so với các thông số khác", #labs(labels) cho title, trục x, trục y
       x = "Giá trị thông số", y = "PRP (Hiệu suất)")
print(p_scatter)

# Lấy luôn biến PRP vào để vẽ Histogram và Boxplot
all_vars_long <- main_data %>%
  select(all_of(cont_cols)) %>%
  pivot_longer(cols = everything(), names_to = "Variable", values_to = "Value")
#dùng cho debug: write.csv(all_vars_long, "du_lieu_cho_histogram_va_boxplot.csv", row.names = FALSE)

# 3.2 ĐỒ THỊ HISTOGRAM
p_hist <- ggplot(all_vars_long, aes(x = Value)) +
  geom_histogram(bins = 20, fill = "skyblue", color = "black", alpha = 0.7) + #bin mặc định là 30, chia khoảng x thành bin cột, nếu lấy nhỏ quá thì máy mạnh bị trùng với máy yếu->thống kê ko có nghĩa
  facet_wrap(~ Variable, scales = "free", ncol = 3) +
  theme_minimal() +
  labs(title = "Histogram của các thông số cấu hình", x = "Giá trị", y = "Tần suất")
print(p_hist)

# 3.3 ĐỒ THỊ BOXPLOT
p_box <- ggplot(all_vars_long, aes(y = Value)) +
  geom_boxplot(fill = "lightgreen", color = "darkgreen", alpha = 0.6) +
  facet_wrap(~ Variable, scales = "free_y", ncol = 3) + theme_minimal() +
  labs(title = "Boxplot kiểm tra điểm ngoại lai (Outliers)", y = "Giá trị")+
  theme(axis.text.x = element_blank(), axis.ticks.x = element_blank())
print(p_box)

# =====================================================================
# Phần 4. Kiểm định mối tương quan
# =====================================================================
# Kiểm tra xem thông số nào có liên hệ mạnh nhất với điểm hiệu suất (PRP)
cor_matrix <- cor(main_data[cont_cols]) #tính hệ số tương quan cho 7 thông số liên tục đã lọc bằng cont_cols (-1<cor<1)
print("Ma trận tương quan giữa các biến:")
print(round(cor_matrix, 3))#làm tròn đến 3 chữ số thập phân, kết quả là một ma trận 7x7
#chỉ quan tâm hàng/cột chứa PRP, check xem giá trị nào lớn nhất



# ============================================================
# Phần 5. Hồi quy tuyến tính
# ============================================================
# BƯỚC LỌC NGOẠI LAI (IQR) ĐỂ MÔ HÌNH CHUẨN XÁC HƠN:
Q1 <- quantile(main_data$PRP, 0.25) #tìm tứ phân vị thứ nhất
Q3 <- quantile(main_data$PRP, 0.75) #tìm tứ phân vị thứ ba
IQR_val <- Q3 - Q1
lower_lim <- Q1 - 1.5 * IQR_val
upper_lim <- Q3 + 1.5 * IQR_val

# Tạo tập dữ liệu sạch (chỉ lấy các máy tính có điểm PRP bình thường)
clean_data <- main_data[main_data$PRP >= lower_lim & main_data$PRP <= upper_lim, ]
#dùng cho debug: (clean_data, "du_lieu_sach_sau_khi_loc.csv", row.names = FALSE)
# Xây dựng mô hình dự báo PRP dựa trên 6 thông số
model_BTL <- lm(PRP ~ MYCT + MMIN + MMAX + CACH + CHMIN + CHMAX, data = clean_data)

# 1. model_BTL$coefficients 
# -> CÁC HỆ SỐ HỒI QUY (BETA): 
# Đây là các "trọng số" b0, b1, b2... dùng để lắp ráp thành phương trình toán học. 
# VD: MMAX = 0.0032 nghĩa là cứ thêm 1 đơn vị RAM thì điểm PRP cộng thêm 0.0032.

# 2. model_BTL$fitted.values 
# -> ĐIỂM DỰ BÁO TRÊN TẬP HUẤN LUYỆN:
# Là danh sách điểm PRP do máy tính TỰ DỰ ĐOÁN LẠI đối với ~180 chiếc máy tính cũ.
# (ta đã dùng chính cái này để làm trục Y khi vẽ biểu đồ chấm điểm ở Phần 6).

# 3. model_BTL$residuals 
# -> SAI SỐ (PHẦN DƯ):
# Là danh sách độ chênh lệch giữa Thực tế và Dự báo của từng chiếc máy tính. 
# Công thức: Residual = Điểm PRP Thực tế - model_BTL$fitted.values.

# 4. model_BTL$call 
# -> NHẬT KÝ CÂU LỆNH:
# R lưu lại chính xác dòng code đã gõ để tạo ra mô hình này 
# (giúp nhớ được mình đã ném những biến nào vào phương trình).

# 5. model_BTL$df.residual 
# -> BẬC TỰ DO CỦA PHẦN DƯ:
# Bằng [Tổng số dòng dữ liệu] trừ đi [Số lượng biến phần cứng + 1].
# Máy tính dùng con số này ở hậu trường để tính ra được cái P-value (xác suất ăn may).

# 6. model_BTL$model 
# -> TẬP DỮ LIỆU ĐÃ HUẤN LUYỆN:
# Toàn bộ cái bảng clean_data  đã được lưu cất ở đây.
cat("KẾT QUẢ MÔ HÌNH HỒI QUY TUYẾN TÍNH:\n\n")
print(summary(model_BTL))


# ============================================================
# Phần 6. Dự đoán hiệu suất máy mới
# ============================================================
# Giả sử công ty nhập về một lô máy tính mới với thông số cụ thể:
# MYCT=100, MMIN=256, MMAX=6000, CACH=256, CHMIN=16, CHMAX=128
new_machine <- data.frame(
  MYCT = 100,
  MMIN = 256,
  MMAX = 6000,
  CACH = 256,
  CHMIN = 16,
  CHMAX = 128
)

# Thực hiện dự báo điểm PRP cho máy tính này
prediction <- predict(model_BTL, newdata = new_machine)#tính toán PRP mới dựa trên newdata và model hồi quy

# in kết quả
print(paste("Điểm PRP dự báo:", round(prediction, 2)))

# --- Biểu đồ so sánh điểm PRP thực tế vs dự báo ---
predicted_values <- predict(model_BTL)#dùng model dự đoán lại hết PRP của 180 máy tính
actual_values <- clean_data$PRP #PRP gốc

# Đưa dữ liệu thực tế và dự báo vào một bảng để ggplot xử lý
plot_data <- data.frame(ThucTe = actual_values, DuBao = predicted_values)#ghép thành 2 cột dữ liệu
#dùng cho debug: write.csv(plot_data, "ket_qua_doi_chieu_mo_hinh.csv", row.names = FALSE)

# Vẽ biểu đồ bằng ggplot2 (Hiện đại & Đồng bộ với các biểu đồ trên)
p_regression <- ggplot(plot_data, aes(x = ThucTe, y = DuBao)) +
  geom_point(color = "steelblue", alpha = 0.7, size = 2.5) +  # Vẽ các điểm máy tính (đồ thị scatter)
  geom_abline(intercept = 0, slope = 1, color = "red", linewidth = 1.2) + # Vẽ đường chéo đỏ (đồ thị linear với slope là a, intercept là b)
  theme_minimal() + 
  labs(title = "So sánh: PRP Thực tế vs Dự báo",
       x = "Điểm PRP Thực tế",
       y = "Điểm PRP Dự báo")

print(p_regression)