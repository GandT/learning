using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Stick : MonoBehaviour {

	// 外部操作変数
	public float force;		// 限界力	(フォース)
	public float torque;    // 限界回転	(トルク)

	// 内部変数
	private CharacterJoint myjoint;

	// 接触時処理
	private void OnCollisionEnter(Collision collision)
	{
		// Bulletタグ同士が触れた時
		if(collision.gameObject.tag == "Bullet") {
			// 非接着の場合のみ処理を行う
			if(myjoint == null) {
				// 接着相手の設定
				myjoint = gameObject.AddComponent<CharacterJoint>();
				myjoint.connectedBody = collision.rigidbody;
			}
		}
	}
}
