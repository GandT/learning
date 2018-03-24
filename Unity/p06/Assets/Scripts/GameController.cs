using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameController : MonoBehaviour {

	[SerializeField] GameObject hazard = null;

	Vector3 spawnValues = new Vector3(6, 0, 16);
	int hazardCount = 10;
	float spawnWait = 0.5f, startWait = 1, waveWait = 4;

	void Start()
	{
		// 初期化

		// 敵を作成
		StartCoroutine(SpawnWaves());
	}
	

	void Update()
	{
		
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
		}
	}
}
