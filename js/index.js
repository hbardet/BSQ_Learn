import { parseArgs } from "util";
import { Bsq } from "./bsq.js"

const { values, positionals } = parseArgs({
  args: Bun.argv,
  options: {
    flag1: {
      type: 'boolean',
    },
    flag2: {
      type: 'string',
    },
  },
  strict: true,
  allowPositionals: true,
});

let NewBsq = new Bsq();
await NewBsq.loadMap(positionals.slice(2)[0])
NewBsq.parseMap();
NewBsq.replaceBsq();

process.stdout.write(NewBsq.map);
