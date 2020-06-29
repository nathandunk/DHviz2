using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CenterCamera : MonoBehaviour
{

    public float scale_factor = 1f;

    static public float scale = 1.0f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        GameObject FinalFrame = GameObject.Find("Frame" + JointTracker.num_joints.ToString());
        Vector3 FinalPosition = FinalFrame.transform.position;
        gameObject.transform.position = new Vector3(FinalPosition.x/2, FinalPosition.y/2, FinalPosition.z/2);

        for (int i = 0; i < JointTracker.num_joints+1; i++){
            GameObject Frame = GameObject.Find("Frame" + i.ToString());
            Transform O = Frame.transform.Find("O0");
            Transform X = Frame.transform.Find("X0");
            Transform Y = Frame.transform.Find("Y0");
            Transform Z = Frame.transform.Find("Z0");

            O.localScale = new Vector3(1f*scale, 1f*scale, 1f*scale);
            
            X.localScale = new Vector3(0.2f*scale, 0.2f*scale, 3.0f*scale);
            X.localPosition = new Vector3(1.5f*scale, 0, 0);

            Y.localScale = new Vector3(0.2f*scale, 0.2f*scale, 3.0f*scale);
            Y.localPosition = new Vector3(0, 0, 1.5f*scale);

            Z.localScale = new Vector3(0.2f*scale, 0.2f*scale, 3.0f*scale);
            Z.localPosition = new Vector3(0, 1.5f*scale, 0);
        }
    }

    public void scale_camera(float value){
        scale = scale_factor*(value/500);
    }
}
