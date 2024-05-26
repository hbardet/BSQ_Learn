class Bsq:
    def __init__(self):
        self.size_map = 0
        self.size_square = 0
        self.map = list("")
        self.x = 0
        self.y = 0

    def loadMap(self, path):
        file = open(path, "r")
        size = file.readline()
        content = file.read()
        self.size_map = int(size)
        self.map = list(content)

    def getCell(self, x, y):
        return (self.map[((y * (self.size_map + 1)) + x)])

    def findBsq(self, x, y):
        tmp_size_square = 1

        while (True):
            if (x + tmp_size_square > self.size_map or y + tmp_size_square > self.size_map):
                return
            for height in range(tmp_size_square):
                if (self.getCell(x + tmp_size_square - 1, y + height) != '.'):
                    return;
            for width in range(tmp_size_square):
                if (self.getCell(x + width , y + tmp_size_square - 1) != '.'):
                    return;
            if (tmp_size_square > self.size_square):
                self.x = x
                self.y = y
                self.size_square = tmp_size_square
            tmp_size_square += 1

    def parseMap(self):
        for height in range(self.size_map):
            for width in range(self.size_map):
                if (self.getCell(width, height) == '.' ):
                    self.findBsq(width, height)

    def replace_bsq(self):
        for height in range(self.y,self.y + self.size_square):
            for width in range(self.x,self.x + self.size_square):
                self.map[((height * (self.size_map + 1)) + width)] = 'x'

