using System.Collections;
using System.Collections.Generic;
using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif
public class LevelSelectPanel : BasePanel
{
    private LevelSelectButton[] levelButtons;

    protected override void Awake()
    {
        base.Awake();

        levelButtons = GetComponentsInChildren<LevelSelectButton>();
    }

    private void Start()
    {
        foreach (var item in levelButtons)
        {
            //if (item.buttonLevelIndex < GameRecord.Instance.beingPassedLevel)
            //{
            //   int specialCoin = GameRecord.Instance.specialCoin[item.buttonLevelIndex - 1];
            //    for (int i = 0; i < 3; i++)
            //    {
            //        if (i < specialCoin)
            //        {
            //            item.specialCoin[i].gameObject.SetActive(true);
            //        }
            //        else
            //        {
            //            item.specialCoin[i].gameObject.SetActive(false);
            //        }
            //    }
            //}
        }
    }


    #region button onclick event

    public void OnClickStoreButton()
    {
        UIManager.PushPanel(UIPanelInfo.PanelType.StorePanel);
    }

    public void OnClickTaskButton()
    {
        UIManager.PushPanel(UIPanelInfo.PanelType.TaskPanel);
    }

    public void Quit()
    {
        GameRecord.Instance.Save(GameRoot.GameRecordJsonSavePath);
#if UNITY_EDITOR
        EditorApplication.isPlaying = false;
#else
		Application.Quit();
#endif
    }
    #endregion



    private void OnApplicationQuit()
    {
        GameRecord.Instance.Save(GameRoot.GameRecordJsonSavePath);
    }

    
}
