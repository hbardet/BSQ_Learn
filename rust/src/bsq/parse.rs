pub trait Parse {
    fn load(&mut self, path: String);
    fn find_bsq(&mut self, x: u32, y: u32);
    fn parse_bsq(&mut self);
    fn get_sell(&self, x: u32, y: u32) -> char;
    fn replace_bsq(&mut self);
}
