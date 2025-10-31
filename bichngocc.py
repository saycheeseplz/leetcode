import threading
import time
import tkinter as tk
import random
from math import sin, cos, radians
from pydub import AudioSegment
from pydub.playback import play

# ====== CẤU HÌNH ======
MUSIC_PATH = "/home/quann/Downloads/ngocc.mp3"     # nhạc chính (20s)
INTRO_MUSIC = "/home/quann/Downloads/intro.mp3"    # nhạc đếm (khoảng 3s) - optional
TOTAL_MUSIC_SECONDS = 20.0 # Nhạc 20 giây

# Thời gian để đọc lời chúc TĨNH sau khi nhạc kết thúc
FINAL_MESSAGE_READ_TIME = 7.0 

# ====== HÀM PHÁT NHẠC (pydub) ======
def play_music(path):
    try:
        sound = AudioSegment.from_mp3(path)
        play(sound)
    except Exception as e:
        print(f"[audio error] {e}")

# ====== LỚP SHOW CHÍNH ======
class BirthdayShow:
    def __init__(self, root):
        self.root = root
        self.root.title("🎂 Happy Birthday — Premium Show")
        self.W, self.H = 1100, 650
        self.root.geometry(f"{self.W}x{self.H}")
        self.root.configure(bg="black")
        self.canvas = tk.Canvas(root, bg="black", highlightthickness=0)
        self.canvas.pack(fill="both", expand=True)

        self.center_text = self.canvas.create_text(self.W//2, self.H//2, text="",
                                                  font=("Brush Script MT", 72, "bold"),
                                                  fill="gold", justify="center")
        # trạng thái
        self.start_time = None
        self.running = True # Sẽ bị TẮT (False) sau khi nhạc + thời gian đọc
        self.final_message_shown = False
        self.cake_shown = False 
        self.cake_items = []

        # start sequence
        threading.Thread(target=self.start_sequence, daemon=True).start()

    # toàn bộ trình tự
    def start_sequence(self):
        # play intro if available
        threading.Thread(target=play_music, args=(INTRO_MUSIC,), daemon=True).start()
        # countdown 3..2..1
        self.countdown(3)

        # start main music and animations
        threading.Thread(target=play_music, args=(MUSIC_PATH,), daemon=True).start()
        self.start_time = time.time()

        # khởi chạy các animation nền & show
        threading.Thread(target=self.background_color_cycle, daemon=True).start()
        threading.Thread(target=self.firework_controller, daemon=True).start()
        threading.Thread(target=self.balloons_controller, daemon=True).start()
        threading.Thread(target=self.confetti_controller, daemon=True).start()
        threading.Thread(target=self.gift_controller, daemon=True).start() # Hộp quà
        threading.Thread(target=self.shooting_star_controller, daemon=True).start() # Mưa sao băng
        ### <<< THAY ĐỔI MỚI >>> ### (Thêm lại Đài phun nước)
        threading.Thread(target=self.middle_fountain_controller, daemon=True).start()
        
        # Logic vòng lặp chính
        trigger_wish_time = 13.0  # Bắt đầu chạy lời chúc ở giây 13

        while time.time() - self.start_time < TOTAL_MUSIC_SECONDS and self.running:
            elapsed = time.time() - self.start_time

            # Kích hoạt lời chúc cuối (sẽ tự kích hoạt bánh kem sau)
            if elapsed >= trigger_wish_time and not self.final_message_shown:
                self.final_message_shown = True
                print(f"Triggering Final Wish at {elapsed:.2f}s")
                threading.Thread(target=self.show_final_message_and_trigger_cake, daemon=True).start()

            self.canvas.itemconfig(self.center_text, text="") # Đảm bảo không có gì ở giữa

            time.sleep(0.2)

        # Đợi cho nhạc kết thúc
        while time.time() - self.start_time < TOTAL_MUSIC_SECONDS and self.running:
            time.sleep(0.1)

        # Đợi thêm thời gian đọc
        print(f"Nhạc kết thúc. Hiển thị lời chúc tĩnh trong {FINAL_MESSAGE_READ_TIME} giây.")
        time.sleep(FINAL_MESSAGE_READ_TIME)
        
        # Kết thúc show
        print("Show kết thúc. Dừng tất cả hiệu ứng.")
        self.running = False # Tắt cờ

    # ====== Đếm ngược có âm thanh (nếu có) ======
    def countdown(self, n):
        font_name = self._choose_script_font(72)
        for i in range(n, 0, -1):
            if not self.running: return
            self.canvas.itemconfig(self.center_text, text=str(i), font=(font_name, 96, "bold"), fill="white")
            self._pulse(self.center_text, minsize=72, maxsize=112, steps=8, speed=0.02)
            time.sleep(0.2)
            time.sleep(0.6)
        if not self.running: return
        self.canvas.itemconfig(self.center_text, text="🎉 Happy Birthday! 🎉", font=(font_name, 64, "bold"), fill="#FFD166")
        self._pulse(self.center_text, minsize=64, maxsize=96, steps=10, speed=0.02)
        time.sleep(1.2)
        self.canvas.itemconfig(self.center_text, text="")

    def _pulse(self, item, minsize=40, maxsize=80, steps=6, speed=0.03):
        try:
            # GIỮ LẠI self.root.update() ở đây là AN TOÀN
            for s in range(steps):
                size = int(minsize + (maxsize - minsize) * (s / steps))
                self.canvas.itemconfig(item, font=(self._choose_script_font(size), size, "bold"))
                self.root.update() 
                time.sleep(speed)
            for s in range(steps):
                size = int(maxsize - (maxsize - minsize) * (s / steps))
                self.canvas.itemconfig(item, font=(self._choose_script_font(size), size, "bold"))
                self.root.update()
                time.sleep(speed)
        except tk.TclError:
            pass # Lỗi nếu cửa sổ bị đóng

    def _choose_script_font(self, size):
        for f in ("Brush Script MT", "Segoe Script", "Lucida Handwriting", "Comic Sans MS", "Helvetica"):
            try:
                return f
            except:
                continue
        return "Helvetica"

    # ====== NỀN: ánh sáng chuyển màu dịu (gradient-ish via rectangle overlay) ======
    def background_color_cycle(self):
        palette = [
            ("#0b1226", "#0b1f3a"),  # deep blue
            ("#1a0b20", "#3a0b2f"),  # maroon purple
            ("#08120b", "#1f3a0b"),  # dark greenish
            ("#1a0812", "#3a0b2f"),  # magenta-ish
        ]
        idx = 0
        rect = None
        while self.start_time is None:
            time.sleep(0.05)
        
        while self.running: 
            try:
                a, b = palette[idx % len(palette)]
                if rect:
                    self.canvas.delete(rect)
                rect = self.canvas.create_rectangle(0, 0, self.W, self.H, fill=a, outline=a)
                
                self.canvas.tag_lower(rect) # Đẩy hình nền 'rect' xuống DƯỚI CÙNG
                
                for step in range(20):
                    if not self.running: break
                    t = step / 20
                    color = self._blend_hex(a, b, t)
                    self.canvas.itemconfig(rect, fill=color, outline=color)
                    time.sleep(0.08)
                idx += 1
            except tk.TclError:
                break 

    def _blend_hex(self, h1, h2, t):
        def hex_to_rgb(h):
            h = h.lstrip("#")
            return tuple(int(h[i:i+2], 16) for i in (0,2,4))
        def rgb_to_hex(rgb):
            return "#{:02x}{:02x}{:02x}".format(*[max(0,min(255,int(v))) for v in rgb])
        r1,g1,b1 = hex_to_rgb(h1)
        r2,g2,b2 = hex_to_rgb(h2)
        r = r1 + (r2-r1)*t
        g = g1 + (g2-g1)*t
        b = b1 + (b2-b1)*t
        return rgb_to_hex((r,g,b))

    # ====== PHÁO HOA nâng cao: nổ, tia sáng, kim tuyến rơi ======
    def firework_controller(self):
        colors = ["#FF3B30", "#FFD60A", "#34C759", "#5AC8FA", "#FF2D55", "#FF9500", "#FFFFFF"]
        while self.start_time is None:
            time.sleep(0.05)
        
        while self.running: 
            time.sleep(random.uniform(0.4, 0.9)) 
            if not self.running: break
            
            x = random.randint(200, self.W - 200)
            y = random.randint(140, self.H//2 + 20)
            color = random.choice(colors)
            threading.Thread(target=self._launch_and_explode, args=(x, y, color), daemon=True).start()

    def _launch_and_explode(self, x, y, color):
        start_y = self.H + 10
        trail = None
        try:
            trail = self.canvas.create_oval(x-2, start_y-2, x+2, start_y+2, fill=color, outline=color)
            steps = 18
            for i in range(steps):
                if not self.running:
                     self.canvas.delete(trail)
                     return
                self.canvas.move(trail, 0, -(start_y - y)/steps)
                time.sleep(0.02)
            self.canvas.delete(trail)
            
            if self.running:
                self._explosion(x, y, color)
                self._sparkle_fall(x, y, color)
        except tk.TclError:
             if trail:
                 try: self.canvas.delete(trail)
                 except: pass

    def _explosion(self, x, y, color):
        particles = []
        try:
            num = random.randint(28, 48)
            for i in range(num):
                ang = radians(random.uniform(0, 360))
                speed = random.uniform(2.4, 6.0)
                vx = cos(ang) * speed
                vy = sin(ang) * speed
                size = random.randint(2, 4)
                dot = self.canvas.create_oval(x, y, x+size, y+size, fill=color, outline=color)
                particles.append([dot, vx, vy, size])
            
            for step in range(28):
                if not self.running: break
                for p in particles:
                    dot, vx, vy, size = p
                    vy += 0.15
                    p[2] = vy
                    self.canvas.move(dot, vx, vy)
                time.sleep(0.025) 
        finally:
            for p in particles:
                try:
                    self.canvas.delete(p[0])
                except:
                    pass

    def _sparkle_fall(self, x, y, color):
        sparkles_to_delete = []
        try:
            for _ in range(12):
                if not self.running: break
                sx = x + random.randint(-60, 60)
                sy = y + random.randint(-10, 20)
                s = self.canvas.create_oval(sx, sy, sx+3, sy+3, fill=color, outline=color)
                sparkles_to_delete.append(s)
                steps = random.randint(18, 30)
                vx = random.uniform(-0.6, 0.6)
                for _ in range(steps):
                    if not self.running: break
                    self.canvas.move(s, vx, random.uniform(2.4, 4.8))
                    time.sleep(0.025) 
        finally:
            for s in sparkles_to_delete:
                try:
                    self.canvas.delete(s)
                except:
                    pass

    # ====== BÁNH KEM 18 (TĨNH) ======
    def _show_sparkle_cake_with_number(self, cx, base_y, number_text):
        if not self.running: return 

        colors = ["#FFD60A", "#FF7A7A", "#FFFFFF", "#F2CC8F", "#E07A5F"]
        cake_sparkles = []

        cake_layers = [
            (cx - 150, base_y - 40, cx + 150, base_y + 20),
            (cx - 120, base_y - 80, cx + 120, base_y - 40),
            (cx - 80, base_y - 110, cx + 80, base_y - 80)
        ]
        
        try:
            # Tạo đốm sáng cho bánh kem
            for layer_coords in cake_layers:
                x1, y1, x2, y2 = layer_coords
                for _ in range(random.randint(100, 180)): 
                    if not self.running: return
                    sx = random.uniform(x1, x2)
                    sy = random.uniform(y1, y2)
                    size = random.randint(2, 4)
                    color = random.choice(colors)
                    sparkle = self.canvas.create_oval(sx, sy, sx+size, sy+size, fill=color, outline=color)
                    cake_sparkles.append(sparkle)

            self.cake_items.extend(cake_sparkles)

            number_font_size = 80
            number_font = (self._choose_script_font(number_font_size), number_font_size, "bold")
            
            number_y_pos = base_y - 120 
            number_item = self.canvas.create_text(cx, number_y_pos, text=number_text, font=number_font, fill="#FFD60A")
            self.cake_items.append(number_item)

            # Hiệu ứng "glow" 1 LẦN DUY NHẤT
            print("Bánh '18' xuất hiện tĩnh.")
            for s in range(number_font_size, number_font_size + 8): # To lên
                if not self.running: break
                self.canvas.itemconfig(number_item, font=(self._choose_script_font(s), s, "bold"))
                time.sleep(0.04)
            for s in range(number_font_size + 7, number_font_size - 1, -1): # Nhỏ lại
                if not self.running: break
                self.canvas.itemconfig(number_item, font=(self._choose_script_font(s), s, "bold"))
                time.sleep(0.04)
            
        except tk.TclError:
            pass

    # ====== HỘP QUÀ (TĨNH, CÓ RUY BĂNG LẠI) ======
    def gift_controller(self):
        while self.start_time is None:
            time.sleep(0.05)
        
        time.sleep(5.0) # Xuất hiện ở giây thứ 5
        if not self.running: return
        threading.Thread(target=self._show_gift, args=("left",), daemon=True).start()

        time.sleep(1.0)
        if not self.running: return
        threading.Thread(target=self._show_gift, args=("right",), daemon=True).start()

    def _show_gift(self, side):
        y = self.H - 170 

        if side == "left":
            x = self.W//2 - 280
            box_color = "#6A5ACD" 
            ribbon_color = "#FFD166" 
        else:
            x = self.W//2 + 280
            box_color = "#FF6B6B" 
            ribbon_color = "#FFE66D" 

        try:
            box = self.canvas.create_rectangle(x-40, y-30, x+40, y+30, fill=box_color, outline=box_color)
            ribbon_v = self.canvas.create_rectangle(x-5, y-40, x+5, y+40, fill=ribbon_color, outline=ribbon_color)
            ribbon_h = self.canvas.create_rectangle(x-40, y-5, x+40, y+5, fill=ribbon_color, outline=ribbon_color)
            items = [box, ribbon_v, ribbon_h] 

            start_y_offset = -80
            for it in items:
                self.canvas.move(it, 0, start_y_offset)

            # Rơi xuống
            for offset in range(0, abs(start_y_offset), 6):
                if not self.running: return
                for it in items: self.canvas.move(it, 0, 6)
                time.sleep(0.02)
                
            # Nảy nhẹ
            for i in range(2):
                if not self.running: return
                for it in items: self.canvas.move(it, 0, -6)
                time.sleep(0.05)
                for it in items: self.canvas.move(it, 0, 6)
                time.sleep(0.05)
        except tk.TclError:
            pass 

    # ====== BÓNG BAY (ĐỘNG) ======
    def balloons_controller(self):
        while self.start_time is None:
            time.sleep(0.05)
        start_at = self.start_time + 3.0
        time.sleep(max(0, start_at - time.time()))
        colors = ["#FF7A7A", "#FFD166", "#7BE495", "#7AD7FF", "#D1A3FF"]
        spawn_points = [120, 260, 840, 980]
        
        while self.running: 
            idx = random.randint(0, len(spawn_points)-1)
            x = spawn_points[idx] + random.randint(-40, 40)
            color = random.choice(colors)
            threading.Thread(target=self._float_balloon, args=(x, self.H + 20, color), daemon=True).start()
            time.sleep(random.uniform(0.7, 1.5)) 
            if not self.running: break

    def _float_balloon(self, x, start_y, color):
        oval, string = None, None
        try:
            r = random.randint(18, 30)
            oval = self.canvas.create_oval(x-r, start_y-2*r, x+r, start_y, fill=color, outline=color)
            string = self.canvas.create_line(x, start_y, x, start_y+60, fill="#DDDDDD")
            steps = random.randint(60, 110)
            for i in range(steps):
                if not self.running: break
                dx = sin(i/10.0) * 2.2
                self.canvas.move(oval, dx, -3.4)
                self.canvas.move(string, dx, -3.4)
                time.sleep(0.03) 
        finally:
            try:
                self.canvas.delete(oval)
                self.canvas.delete(string)
            except:
                pass

    # ====== KIM TUYẾN (ĐỘNG) ======
    def confetti_controller(self):
        colors = ["#FFD166", "#FF7A7A", "#7BE495", "#7AD7FF", "#FFFFFF", "#FF9500"]
        while self.start_time is None:
            time.sleep(0.05)
            
        while self.running: 
            if not self.running: break
            
            x = random.randint(0, self.W)
            color = random.choice(colors)
            threading.Thread(target=self._fall_sparkle, args=(x, color), daemon=True).start()
            time.sleep(random.uniform(0.03, 0.15)) 

    def _fall_sparkle(self, x_start, color):
        sparkle = None
        try:
            y_start = -10
            size = random.randint(3, 6)
            sparkle = self.canvas.create_rectangle(x_start, y_start, x_start+size, y_start+size, fill=color, outline=color)
            
            vx = random.uniform(-1.5, 1.5)
            vy = random.uniform(2.5, 5.0)
            
            while self.canvas.coords(sparkle)[1] < self.H and self.running:
                self.canvas.move(sparkle, vx, vy)
                time.sleep(0.02) 
        finally:
            try:
                self.canvas.delete(sparkle)
            except:
                pass

    ### <<< THAY ĐỔI MỚI >>> ### (Thêm lại Đài phun nước)
    def middle_fountain_controller(self):
        while self.start_time is None:
            time.sleep(0.05)
        time.sleep(6.0) # Bắt đầu ở giây thứ 6

        colors = ["#FFD166", "#7AD7FF", "#FFFFFF", "#FF7A7A"]
        
        # Chạy TỪ GIỜ (6s) cho đến KHI LỜI CHÚC CUỐI XUẤT HIỆN
        while self.running and not self.final_message_shown:
            x = self.W // 2
            y = self.H // 2 + 50 # Bắn từ giữa
            color = random.choice(colors)
            
            for _ in range(3):
                threading.Thread(target=self._fountain_particle, args=(x, y, color), daemon=True).start()
            
            time.sleep(0.05) # Bắn liên tục
            
    def _fountain_particle(self, x, y, color):
        particle = None
        try:
            size = random.randint(2, 4)
            particle = self.canvas.create_oval(x, y, x+size, y+size, fill=color, outline=color)
            
            vx = random.uniform(-4.5, 4.5) # Tỏa ra 2 bên
            vy = random.uniform(-8.0, -4.0) # Bắn lên trên
            gravity = 0.25 # Trọng lực kéo xuống

            for _ in range(40): # Tuổi thọ của hạt
                if not self.running: break
                self.canvas.move(particle, vx, vy)
                vy += gravity 
                # <<< ĐÃ XÓA self.root.update() >>> (An toàn)
                time.sleep(0.02)
        finally:
            try:
                self.canvas.delete(particle)
            except:
                pass

    # ====== HIỆU ỨNG MƯA SAO BĂNG ======
    def shooting_star_controller(self):
        while self.start_time is None:
            time.sleep(0.05)
        
        while self.running:
            ### <<< THAY ĐỔI MỚI >>> ### (Nhiều sao băng hơn)
            time.sleep(random.uniform(1.0, 3.5)) 
            if not self.running: break
            
            start_x = random.randint(self.W // 4, self.W - 50) 
            start_y = random.randint(-50, self.H // 3) 

            threading.Thread(target=self._create_shooting_star, args=(start_x, start_y), daemon=True).start()

    def _create_shooting_star(self, start_x, start_y):
        star_color = "#FFFFFF" 
        trail_color = "#FFD60A" 

        star_items = []
        try:
            star_head = self.canvas.create_oval(start_x, start_y, start_x+8, start_y+8, fill=star_color, outline=star_color)
            star_items.append(star_head)

            trail_length = random.randint(20, 50)
            trail_segments = []
            
            vx = random.uniform(-6, -3) 
            vy = random.uniform(3, 6) 

            for i in range(trail_length):
                if not self.running: break
                seg_x1 = start_x - i * (vx / 4.0) 
                seg_y1 = start_y - i * (vy / 4.0)
                seg_x2 = seg_x1 + 4
                seg_y2 = seg_y1 + 4
                
                trail_segment = self.canvas.create_rectangle(seg_x1, seg_y1, seg_x2, seg_y2, 
                                                            fill=trail_color, outline=trail_color)
                star_items.append(trail_segment)
                trail_segments.append(trail_segment)
            
            for step in range(80): # Thời gian bay
                if not self.running: break
                
                for item in star_items:
                    self.canvas.move(item, vx, vy)
                time.sleep(0.02) # Tốc độ bay
                
                if len(trail_segments) > 0 and step % 4 == 0:
                    try:
                        self.canvas.delete(trail_segments.pop(0))
                    except: pass
                    
                if random.random() < 0.3:
                    spark_x = self.canvas.coords(star_head)[0] + random.uniform(-10, 10)
                    spark_y = self.canvas.coords(star_head)[1] + random.uniform(-10, 10)
                    spark = self.canvas.create_oval(spark_x, spark_y, spark_x+2, spark_y+2, 
                                                    fill=random.choice([star_color, trail_color]), outline=random.choice([star_color, trail_color]))
                    self.canvas.after(random.randint(200, 500), lambda s=spark: self.canvas.delete(s)) 

        finally:
            for item in star_items:
                try:
                    self.canvas.delete(item)
                except:
                    pass

    # ====== LỜI CHÚC (TĨNH, GLOW MÀU NHẸ) VÀ KÍCH HOẠT BÁNH KEM ======
    def show_final_message_and_trigger_cake(self):
        self.canvas.itemconfig(self.center_text, text="")

        message = "💖 Chúc em tuổi 18 rực rỡ\nvà mãi mãi là cô bé vui tươi, rạng ngời đó nhé! 🌸"
        font_name = self._choose_script_font(36)
        
        x = self.W // 2
        y = self.H // 2 - 50 
        
        glow_colors = ["#FFC300", "#FFD700", "#FFFACD", "#FFFFE0", "#FFD166", "#FFB6C1"] 
        text_item = None

        try:
            text_item = self.canvas.create_text(x, y, text="", font=(font_name, 28, "bold"),
                                              fill=glow_colors[0], justify="center") 
            
            # --- BẮT ĐẦU GÕ CHỮ (Typewriter effect) ---
            char_count = 0
            for ch in message:
                if not self.running: return
                current = self.canvas.itemcget(text_item, "text")
                self.canvas.itemconfig(text_item, text=current + ch)
                time.sleep(0.06) 
                char_count += 1
            
            print(f"Typewriter finished after {char_count} chars.")

            # === KÍCH HOẠT BÁNH KEM ===
            if self.running and not self.cake_shown:
                self.cake_shown = True 
                print("Triggering Cake '18'...")
                threading.Thread(target=self._show_sparkle_cake_with_number, 
                                 args=(self.W // 2, self.H - 120, "18"), 
                                 daemon=True).start()
            
            # === GLOW MÀU NHẸ (ỔN ĐỊNH) ===
            print("Lời chúc xuất hiện tĩnh (glow màu nhẹ).")
            base_size = 34
            current_color_idx = 0
            
            # Fade-in màu ban đầu
            for c in ["#555555", "#a899a9", "#ffdfe6", "#ffd166", "#fff8e7"]:
                if not self.running: return
                self.canvas.itemconfig(text_item, fill=c)
                time.sleep(0.1) 

            # Vòng lặp glow màu (giữ nguyên kích thước chữ)
            while self.running: 
                if not self.running: break
                
                c1 = glow_colors[current_color_idx % len(glow_colors)]
                c2 = glow_colors[(current_color_idx + 1) % len(glow_colors)]
                
                for step in range(10): # Blend 10 bước
                    if not self.running: break
                    t = step / 10
                    blended_color = self._blend_hex(c1, c2, t)
                    self.canvas.itemconfig(text_item, fill=blended_color)
                    time.sleep(0.07) 
                
                current_color_idx += 1
                if not self.running: break
                time.sleep(0.3) 

        except tk.TclError:
             pass


# ====== RUN ======
if __name__ == "__main__":
    root = tk.Tk()
    app = BirthdayShow(root)
    try:
        root.mainloop()
    except KeyboardInterrupt:
        pass