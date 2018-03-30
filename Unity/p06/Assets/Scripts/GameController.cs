using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameController : MonoBehaviour {

	[SerializeField] GameObject hazard = null;

	Vector3 spawnValues = new Vector3(6, 0, 16);
	int hazardCount = 10;
	int score = 0;
	float spawnWait = 0.5f, startWait = 1, waveWait = 4;
	bool gameoverFlag, restaretFlag;

	public GUIText scoreText, restartText, gameoverText;

	void Start()
	{
		// 初期化
		score = 0;
		gameoverFlag = restaretFlag = false;
		restartText.text =  gameoverText.text = "";
		UpdateScore();

		// 敵を作成
		StartCoroutine(SpawnWaves());
	}
	

	void Update()
	{
		// コンティニュー
		if(restaretFlag && Input.GetKeyDown(KeyCode.X)) SceneManager.LoadScene(SceneManager.GetActiveScene ().name);
	}


	IEnumerator SpawnWaves()
	{
		yield return new WaitForSeconds(startWait);

		while(true){ 
			for(int i = 0; i < hazardCount; ++i){
				Vector3 spawnPosition = new Vector3(Random.Range(-spawnValues.x, spawnValues.x), spawnValues.y, spawnValues.z);
				Quaternion spawnRotation = Quaternion.identity; // 無回転

				Instantiate(hazard, spawnPosition, spawnRotation);

				yield return new WaitForSeconds(spawnWait);
			}

			yield return new WaitForSeconds(waveWait);

			// ゲームオーバー時処理
			if(gameoverFlag) {
				restartText.text = "Press 'X' for restart.";
				restaretFlag = true;
				break;
			}
		}
	}


	void UpdateScore()
	{
		scoreText.text = "Score: " + score;
	}


	public void AddScore(int additonalScoreValue)
	{
		// スコアの加算
		score += additonalScoreValue;

		// 表示更新
		UpdateScore();
	}

	public void Gameover()
	{
		gameoverText.text = "Game Over";
		gameoverFlag = true;
	}
}
