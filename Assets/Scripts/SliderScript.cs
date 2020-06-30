using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SliderScript : MonoBehaviour
{
    float a;
    float alpha;
    float d;
    float theta;

    string curr_slider;
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setA(){curr_slider = "a";}
    public void setAlpha(){curr_slider = "alpha";}
    public void setD(){curr_slider = "d";}
    public void setTheta(){curr_slider = "theta";}

    public void slider_change(float value)
    {
        // var current_name = gameObject.transform.name;
        var name = gameObject.transform.name;
        var num = name.Substring(name.Length - 1);
        
        var frame = GameObject.Find("Frame" + num);

        var current_position = frame.transform.localPosition;
        var current_angles   = frame.transform.localEulerAngles;

        int joint_index = int.Parse(num)-1;
        
        switch (curr_slider)
        {
            case "a":
                a = value/Constants.scale_factor;
                JointTracker.a[joint_index] = (double)a;
                break;
            case "alpha":
                alpha = value/Constants.scale_factor;
                JointTracker.alpha[joint_index] = (double)alpha;
                break;
            case "d":
                d = value/Constants.scale_factor;
                JointTracker.d[joint_index] = (double)d;
                break;
            case "theta":
                theta = value/Constants.scale_factor;
                JointTracker.theta[joint_index] = (double)theta;
                break;
            default:
                break;
        }

        Vector3 test_axis = new Vector3(0,d,0);
        frame.transform.localPosition = new Vector3(a,0,0) + Quaternion.AngleAxis(-alpha,Vector3.right)*test_axis;
        
        frame.transform.localRotation = Quaternion.AngleAxis(-alpha,Vector3.right)*Quaternion.AngleAxis(-theta, Vector3.up);
    }
}
