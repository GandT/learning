using UnityEngine;
using System.Collections;

public class Jump : MonoBehaviour
{
	float force = 7.5f;

	void Update()
	{
		if(Input.GetKeyDown(KeyCode.Space))
		{
			Rigidbody rb = GetComponent<Rigidbody>();
			rb.velocity = new Vector3(0, 0, 0);
			rb.AddForce(new Vector3(0, force, 0), ForceMode.Impulse);
		}
	}
}