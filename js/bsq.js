
export class Bsq {
  constructor() {
    this.size_map = 0
    this.size_square = 0
    this.map = ""
    this.X = 0
    this.Y = 0
  }

  async loadMap(path) {
    let rawMap = await Bun.file(path).text();
    let firstLine = rawMap.split('\n')[0].split(' ');

    this.size_map = parseInt(firstLine[0]);
    this.map = rawMap.split('\n').splice(1).join('\n');
  }

  cell(x, y) {
      return this.map[((y * (this.size_map + 1)) + x)];
  }

  findBsq(x, y) {
    let size_square = 1;

    while (true) {
      if (x + size_square > this.size_map || y + size_square > this.size_map) {
        return;
      }

      for (let height = 0; height < size_square; height++) {
        if (this.cell(x + size_square - 1, y + height) != '.') {
          return;
        }
      }
      for (let width = 0; width < size_square; width++) {
        if (this.cell(x + width, y + size_square - 1) != '.') {
          return;
        }
      }
      if (size_square > this.size_square) {
        this.size_square = size_square;
        this.X = x;
        this.Y = y;
      }
      size_square++;
    }
  }

  parseMap() {
    for (let height = 0; height < this.size_map; height++) {
      for (let width = 0; width < this.size_map; width++) {
        if (this.cell(width, height) == '.') {
          this.findBsq(width, height);
        }
      }
    }
  }

  replaceBsq() {
    let newMap = this.map.split('');
    for (let height = 0; height < this.size_square; height++) {
      for (let width = 0; width < this.size_square; width++) {
        newMap[(((height + this.Y) * (this.size_map + 1)) + (width + this.X))] = 'x';
      }
    }
    this.map = newMap.join('');
  }
}

