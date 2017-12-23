/*
    2017.12.8
    カラムに制約を付ける
*/

drop table if exists tweets;

create table if not exists tweets(
    id integer primary key,
    username text not null,
    tweet text unique,
    favnum integer default 0 check (favnum >= 0),
    RTnum integer default 0 check (favnum >= 0)
);

insert into tweets (username, tweet) values ('osagetan', 'ぽよぽよなんきんだるまちゃん');
insert into tweets (id, username, tweet) values (null, 'osagetan', '夜警ドラゴン');
insert into tweets (username, tweet) values ('osagetan', '悩め無明');

insert into tweets (username, tweet) values ('osagetan', '重複夜警');
insert into tweets (username, tweet) values ('osagetan', '重複夜警');

insert into tweets (tweet) values ('無効夜警');

insert into tweets (username, tweet,favnum) values ('osagetan', '無効無明', -100);

-- 結果を表示
select * from tweets;