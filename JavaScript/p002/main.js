var s_t_r_i_n_g = "こたたん";
console.log(s_t_r_i_n_g);
var x = 1, y = 2, z = 3, mojiretsu = "moji";
console.log(x);
console.log(y);
console.log(z);
console.log(mojiretsu);

// どうもhtmlに日本語を書かずに.jsにだけ日本語を書くと文字化けが発生するようである
// htmlにcharset="SHIFT_JIS"で治る（というかなんでUTF-8になってたんだよ違うのにあとcharasetじゃなくてcharsetだっつってんだろ）