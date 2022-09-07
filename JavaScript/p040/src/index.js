import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';

const Square = (props) => {
  return (
    <button
      className="square" 
      onClick={props.onClick}
    >
      { props.value }
    </button>
  );
}

class Board extends React.Component {
  // propsを受け取るコンストラクタ（おそらくReactでそういうルールになってる）
  constructor(props){
    // 親のコンストラクタを呼び出し
    super(props);

    // 初期stateとして9マスの状態を保持する配列を作成
    this.state = {
      squares: Array(9).fill(null),
      isXNext: true,
    };
  }

  handleClick(i){
    // this.state.squares のコピー配列を作る（引数無しslice()は配列全コピー）
    const squares = this.state.squares.slice();

    // 勝負終了済み or クリック済みボタン選択の場合は処理を行わない
    if(calculateWinner(squares) || squares[i]) return;

    // isXNextの値に応じてXかOか決める
    squares[i] = this.state.isXNext ? 'X' : 'O';

    // this.state.squares は直接触ってはいけないのでこういう書き方で更新する
    this.setState({
      squares: squares,
      isXNext: !this.state.isXNext,
    });
  }

  renderSquare(i) {
    return (
      <Square 
        value={this.state.squares[i]}
        onClick={() => this.handleClick(i)}
      />
    )
  }

  render() {
    // 勝者判別
    const winner = calculateWinner(this.state.squares);

    // 手番表記
    let status;
    if(winner){
      status = `${winner} の勝利！`;
    }else{
      status = `${this.state.isXNext ? 'X' : 'O'} の番です`;
    }

    return (
      <div>
        <div className="status">{status}</div>
        <div className="board-row">
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
        </div>
        <div className="board-row">
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
        </div>
        <div className="board-row">
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
      </div>
    );
  }
}

class Game extends React.Component {
  render() {
    return (
      <div className="game">
        <div className="game-board">
          <Board />
        </div>
        <div className="game-info">
          <div>{/* status */}</div>
          <ol>{/* TODO */}</ol>
        </div>
      </div>
    );
  }
}


// ========================================

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Game />);

// ========================================

const calculateWinner = (squares) => {
  const winning_lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];
  for (let i = 0; i < winning_lines.length; i++) {
    const [a, b, c] = winning_lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
}