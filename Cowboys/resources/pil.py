from PIL import Image
import math
import os

# Your own color pallet
# If your image has no transparent pixels use COLORS_RGB, else COLORS_RGBA

COLORS_RGBA = {(92, 148, 252, 255): 'C_SKY',  # sky
               (0, 0, 0, 255): "C_BLACK",  # black
               (252, 252, 252, 255): "C_WHITE",  # white
               (60, 188, 252, 255): "C_LIGHT_BLUE",  # light blue
               (200, 76, 12, 255): "C_DARK_ORANGE",  # dark orange
               (252, 152, 56, 255): "C_LIGHT_ORANGE",  # light orange
               (255, 188, 176, 255): "C_SKIN",  # skin
               (0, 168, 0, 255): "C_DARK_GREEN",  # dark green
               (128, 208, 16, 255): "C_LIGHT_GREEN",  # light green
               (216, 40, 0, 255): "C_RED",  # red
               (230, 156, 33, 255): "C_LIGHT_YELLOW",  # light yellow
               (113, 65, 13, 255): "C_BROWN",  # dark red
               (52, 50, 48, 255): "C_GRAY",  # dark yellow
               (101, 101, 101, 255): "C_LIGHT_GRAY",  # dark yellow
               (0, 0, 0, 0): "__NO__"  # transparent
               }

COLORS_RGB = {(92, 148, 252): 'C_SKY',  # sky
              (0, 0, 0): "C_BLACK",  # black
              (252, 252, 252): "C_WHITE",  # white
              (60, 188, 252): "C_LIGHT_BLUE",  # light blue
              (200, 76, 12): "C_DARK_ORANGE",  # dark orange
              (252, 152, 56): "C_LIGHT_ORANGE",  # light orange
              (255, 188, 176): "C_SKIN",  # skin
              (0, 168, 0): "C_DARK_GREEN",  # dark green
              (128, 208, 16): "C_LIGHT_GREEN",  # light green
              (216, 40, 0): "C_RED",  # red
              (230, 156, 33): "C_LIGHT_YELLOW",  # light yellow
              (181, 49, 33): "C_DARK_RED",  # dark red
              (136, 111, 0): "C_DARK_YELLOW",  # dark yellow
              (0, 0, 0): "__NO__"  # transparent
              }


def clamp(x):
    return max(0, min(x, 255))


def rgb2hex(r, g, b):
    return "# (0:02x ) (1:02x ) (2:02x )".format(clamp(r), clamp(g), clamp(b))


def closest_color(rgb, mode):
    color_diffs = []
    if mode == "RGBA":
        r, g, b, a = rgb
        for color in COLORS_RGBA.keys():
            cr, cg, cb, ca = color
            color_diff = math.sqrt(
                abs(r - cr) ** 2 + abs(g - cg) ** 2 + abs(b - cb) ** 2 + abs(a - ca)**2)
            color_diffs.append((color_diff, color))
    elif mode == "RGB":
        r, g, b = rgb
        for color in COLORS_RGB.keys():
            cr, cg, cb = color
            color_diff = math.sqrt(
                abs(r - cr) ** 2 + abs(g - cg) ** 2 + abs(b - cb) ** 2)
            color_diffs.append((color_diff, color))
    return min(color_diffs)[1]


def convert_image(image_filepath):
    image = Image.open(image_filepath)

    pix_value = image.load()
    width, height = image.size
    f = open(os.path.splitext(image_filepath)[0] + '.txt', 'w')
    f.write("{\n")
    for y in range(height):
        for x in range(width):
            if image.mode == "RGBA":
                if x == width-1 and y == height-1:
                    print("hi")
                    color_code = COLORS_RGBA[closest_color(
                        pix_value[x, y], image.mode)]
                    f.write(color_code)
                else:
                    color_code = COLORS_RGBA[closest_color(
                        pix_value[x, y], image.mode)] + ","
                    f.write(color_code)
            elif image.mode == "RGB":
                if x == width-1 and y == height-1:
                    print("hi")
                    color_code = COLORS_RGB[closest_color(
                        pix_value[x, y][0:3], image.mode)]
                    f.write(color_code)
                else:
                    color_code = COLORS_RGB[closest_color(
                        pix_value[x, y][0:3], image.mode)] + ","
                    f.write(color_code)
        f.write("\n")
    f.write("};")
    f.close()


if __name__ == '__main__':
    # Folder name with your images

    # for filename in os.listdir("Converting"):
    #     if filename.endswith(".png"):
    #         convert_image("Converting/" + filename)

    for filename in os.listdir("objects/"):
        if filename.endswith(".png"):
            convert_image("objects/" + filename)
