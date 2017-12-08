/*
    2017.12.2
    テーブルの作成
*/

-- SQLは;が要る

-- テーブルの作成
CREATE TABLE IF NOT EXISTS internationals (
    id,
    nation,
    gdp
);


-- テーブル一覧
.tables

--- テーブルの構造
.schema
-- なんか青くならんのでSQLite専用のアレかもしれない　→　青くなるのがそもそもおかしい
-- あと行の直後にコメントを入れると壊れるっぽい。なんとかならんのか。