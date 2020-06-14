
using UnityEngine.UI;
using DG.Tweening;
public class MainMenuPanel : BasePanel
{
    



    #region button click event

    public void OnClickSystemSettingButton()
    {
        UIManager.PushPanel(UIPanelInfo.PanelType.SystemSettingPanel);
    }

    public void OnClickPauseButton()
    {
        UIManager.PushPanel(UIPanelInfo.PanelType.PausePanel);
    }

    #endregion

    

    
}
