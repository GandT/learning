using UnityEngine;
using System.Collections;

public class Walk : MonoBehaviour
{
	public float speed = 1f;

	void Update()
	{
		Vector3 move = new Vector3(0, 0, 0);

		if(Input.GetKey(KeyCode.RightArrow)) {
			move += new Vector3(8, 0, 0);
		}

		if(Input.GetKey(KeyCode.LeftArrow)) {
			move += new Vector3(-8, 0, 0);
		}

		if(Input.GetKey(KeyCode.UpArrow)) {
			move += new Vector3(0, 0, 8);
		}

		if(Input.GetKey(KeyCode.DownArrow)) {
			move += new Vector3(0, 0, -8);
		}

		transform.Translate(move * Time.deltaTime * speed );
	}
}