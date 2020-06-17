using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraManager : MonoBehaviour
{
    float speed = 10;
    public GameObject target;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // gameObject.transform.LookAt(target.transform);
        float minFov = 15f;
        float maxFov = 90f;
        float sensitivity = 10f;
        
        float fov = Camera.main.fieldOfView;
        fov += Input.GetAxis("Mouse ScrollWheel") * sensitivity;
        fov = Mathf.Clamp(fov, minFov, maxFov);
        Camera.main.fieldOfView = fov;

        if(Input.GetMouseButton(0)) {
            transform.Rotate(new Vector3(Input.GetAxis("Mouse Y") * speed, -Input.GetAxis("Mouse X") * speed, 0));
            float X = transform.rotation.eulerAngles.x;
            float Y = transform.rotation.eulerAngles.y;
            transform.rotation = Quaternion.Euler(X, Y, 0);
        }
    }
}
