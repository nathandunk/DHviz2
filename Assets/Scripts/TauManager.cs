using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TauManager : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void TauSlider(float value){
        var name = gameObject.transform.name;
        var num = name.Substring(name.Length - 1);

        int joint_index = int.Parse(num)-1;

        ModelTest.Taus[joint_index] = (double)value/10000;
    }
}
