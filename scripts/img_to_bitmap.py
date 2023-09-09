import argparse
import matplotlib.pyplot as plt

def get_rgb(img_path: str):
    """
    Takes in the path to a 16 x 16 PNG, and prints out an 1D array of length 16 x 16 x 3 
    that can be copied and pasted to `img_array` variable in `draw_bitmap.ino` 
    for displaying on an 16 x 16 LED array. The input image can be drawn and saved
    as PNG using "https://www.pixilart.com/draw".

    Inputs:
    img_path: path to 16 x 16 image for displaying
    """
    string = ""
    img = plt.imread(img_path)[:,:,:3] * 255
    img[0::2, :] = img[0::2, ::-1]
    string = string + "{"
    for w in range(img.shape[0]):
        for h in range(img.shape[1]):
            for rgb in range(img.shape[2]):
                string = string + str(int(img[w][h][rgb]))
                if not (w == 15 and h == 15 and rgb == 2):
                    string = string + ", "
    string = string + "};"
    print(string)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='return rgba values')
    parser.add_argument('--img', default='./images/fox.png', help='path to image')
    args = parser.parse_args()
    
    get_rgb(args.img)
