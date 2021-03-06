module mul(A,B,O,ck,start,fin);


input [7:0] A, B;
input ck,start;
output [16:0] O;
output fin;

reg [3:0] st;
reg [7:0] AIN, BIN;
reg [16:0] O;
reg fin;

//筆算による乗算（組み合わせ回路）
always @(posedge ck) begin
	if( start == 1 ) begin
		//初期化
		fin <= 0;	//finishフラグの初期化
		AIN <= A;	//かけられる数
		BIN <= B;	//かける数
		O <= 0;		//計算結果
		st <= 0;
	end else begin
		case (st)	//status
		0: O <= (O<<1) + AIN * BIN[7];
		1: O <= (O<<1) + AIN * BIN[6];
		2: O <= (O<<1) + AIN * BIN[5];
		3: O <= (O<<1) + AIN * BIN[4];
		4: O <= (O<<1) + AIN * BIN[3];
		5: O <= (O<<1) + AIN * BIN[2];
		6: O <= (O<<1) + AIN * BIN[1];
		7: begin O <= (O<<1) + AIN * BIN[0]; fin<= 1; end	//複文により計算および結果を表示
		8: begin fin <= 0; st = 0; end
		endcase
		st <= st + 1 ;	//状態遷移
	end
end

endmodule

