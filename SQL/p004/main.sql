/*
    2017.12.02
    テーブルの編集
*/

-- テーブルの削除
drop table if exists tweet;

create table if not exists tweet (
    id integer primary key,
    usrname text,
    tweet text,
    client text
);

.tables

-- テーブル名変更
alter table tweet rename to tweets;

.tables

-- カラムの追加
alter table tweets add column like_num integer;
alter table tweets add column retweet_num integer;
-- カラムの削除はできないらしい（新しいテーブルを作ればよい

.tables
.schema