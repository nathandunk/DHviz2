using System;
using UnityEngine;
using TMPro;
 
public class ModelTest : MonoBehaviour
{
    public GameObject ControlPanel;

    bool started = false;

    public double[] Qs = new double[3];
    public double[] Qref = new double[3];
    private double[] Qrefrad = new double[3];
    public float[] thetas = new float[3];

    static public double[] Taus = new double[3];
    private double[] TausSend = new double[3];

    static IntPtr nativeLibraryPtr;
 
    // delegate int MultiplyFloat(float number, float multiplyBy);
    // delegate void DoSomething(string words);

    delegate void start();
    delegate void stop();
    delegate void get_Q(double[] Qs); 
    delegate void set_Tau(double[] Tau);
    delegate void set_Qref(double[] Qref);
 
    public void start_sim()
    {
        Debug.Log("Trying to load library");
        if (nativeLibraryPtr != IntPtr.Zero) return;
 
        nativeLibraryPtr = Native.LoadLibrary("cpp/build/Release/dynamic_model");
        if (nativeLibraryPtr == IntPtr.Zero)
        {
            Debug.LogError("Failed to load native library");
        }
        Native.Invoke<start>(nativeLibraryPtr);
        Debug.Log("Successfully loaded library");
        started = true;
    }
 
    void Update()
    {
        // Native.Invoke<DoSomething>(nativeLibraryPtr, "Hello, World!");
        // int result = Native.Invoke<int, MultiplyFloat>(nativeLibraryPtr, 10, 5); // Should return the number 50.

        if(started){

            Native.Invoke<get_Q>(nativeLibraryPtr,Qs);

            for (int i = 0; i < JointTracker.num_joints-1; i++){
                thetas[i] = (float)(Mathf.Rad2Deg*Qs[i]);
                TausSend[i] = Taus[i]/100;
                Qrefrad[i] = Qref[i]*Mathf.Deg2Rad;
            }

            for (int i = 0; i < JointTracker.num_joints-1; i++){
                GameObject frame = GameObject.Find("Frame" + (i+1).ToString());
                frame.transform.localRotation = Quaternion.AngleAxis(-(float)JointTracker.alpha[i],Vector3.right)*Quaternion.AngleAxis(-((float)JointTracker.theta[i]+thetas[i]), Vector3.up);
            }

            Native.Invoke<set_Tau>(nativeLibraryPtr,TausSend);

            Native.Invoke<set_Qref>(nativeLibraryPtr,Qref);

            for (int i = 0; i < JointTracker.num_joints-1; i++){
                float angle = ((float)Qs[i] - 2*Mathf.PI*Mathf.Floor( ((float)Qs[i]+Mathf.PI)/(2*Mathf.PI)))*Mathf.Rad2Deg; 
                ControlPanel.transform.Find("Control"+(i+1).ToString()).Find("qInput").GetComponent<TMP_InputField>().text = angle.ToString("F2");
            }
        }
    }
 
    void OnApplicationQuit()
    {
        if(started) Native.Invoke<stop>(nativeLibraryPtr);

        if (nativeLibraryPtr == IntPtr.Zero) return;
 
        Debug.Log(Native.FreeLibrary(nativeLibraryPtr)
                      ? "Native library successfully unloaded."
                      : "Native library could not be unloaded.");
    }
}