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
  renderSquare(i) {
    return (
      <Square 
        value={this.props.squares[i]}
        onClick={() => this.props.onClick(i)}
      />
    )
  }

  render() {
    return (
      <div>
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
  constructor(props){
    super(props);

    this.state = {
      history: [{
        squares: Array(9).fill(null),
      }],
      stepNumber: 0,
      isXNext: true,
    }
  }

  handleClick(i){
    const history = this.state.history.slice(0, this.state.stepNumber + 1);
    const current = history[history.length - 1];
    const squares = current.squares.slice();

    // 勝負終了済み or クリック済みボタン選択の場合は処理を行わない
    if(calculateWinner(squares) || squares[i]) return;

    // isXNextの値に応じてXかOか決める
    squares[i] = this.state.isXNext ? 'X' : 'O';

    // this.state.squares は直接触ってはいけないのでこういう書き方で更新する
    this.setState({
      history: history.concat([{
        squares: squares,
      }]),
      stepNumber: history.length,
      isXNext: !this.state.isXNext,
    });
  }

  jumpTo(step){
    this.setState({
      stepNumber: step,
      isXNext: (step % 2 === 0),
    })
  }

  render() {
    const history = this.state.history;
    const current = history[this.state.stepNumber];

    // 勝者判別
    const winner = calculateWinner(current.squares);

    // 手番移動
    const moves = history.map((step, move) => {
      // 手番移動ボタンの表示テキスト
      const description = move ?
        `${move}手目へ移動` :
        "ゲーム開始時へ移動";

      return(
        <li key={move}>
          <button onClick={() => this.jumpTo(move)}>{description}</button>
        </li>
      );
    })

    // 手番表記
    let gamMessage;
    if(winner){
      gamMessage = `${winner} の勝利！`;
    }else{
      gamMessage = `${this.state.isXNext ? 'X' : 'O'} の番です`;
    }

    return(
      <div className="game">
        <div className="game-board">
          <Board
            squares={current.squares}
            onClick={(i) => {this.handleClick(i)}}
          />
        </div>
        <div className="game-info">
          <div>{gamMessage}</div>
          <ol>{moves}</ol>
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