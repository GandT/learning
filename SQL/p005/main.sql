/*
    2017.12.7
    レコードの挿入
*/

drop table if exists tweets;

create table if not exists tweets(
    id integer primary key,
    username,
    tweet
);

insert into tweets (username, tweet) values ('osagetan', 'ぽよぽよなんきんだるまちゃん');
insert into tweets (id, username, tweet) values (null, 'osagetan', '夜警ドラゴン');
insert into tweets (username, tweet) values ('osagetan', '悩め無明');
insert into tweets (username, tweet) values ('osagetan', '飛翔体 ― ''HISHOUTAI''');
insert into tweets (username, tweet) values ('osagetan', 'ピザピザピザ
ピザ

ピザ



ピ

　　　　ザ');

-- select文の結果は画面上にでるぽい
select * from tweets;