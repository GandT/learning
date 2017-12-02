/*
    2017.12.02
    データ型
*/

-- テーブルの作成
create table if not exists internationals (
    -- 主キー（主キーとは？？？）
    id integer primary key,
    -- データ型は何も書かないと（というか書いても勝手に決まる。便利ですね。本当に便利か？
    nation text,
    gdp float,
    bin blob,
    -- null型、何に使うんでしょうね。いや「null: false」とかのアレ用だとは思うのですが。
    nil null
);

.tables
.schema