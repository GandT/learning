/*
    2019.8.9
    reduce関数の練習
*/

// reduceで呼び出される関数
const called_function = (former, latter, index) => {
    const res = former + latter + index;
    console.log(index);
    return res;
};

// reduceの対象とする配
const array = [1,1,1,1,1];

// reduce実行と結果表示
const result1 = array.reduce(called_function);  // 1*5 + 1+2+3+4+ = 15
console.log("結果："+result1);

const result2 = array.reduce(called_function, 10); // 10 + 1*5 + 0+1+2+3+4 = 25
console.log("結果："+result2);


