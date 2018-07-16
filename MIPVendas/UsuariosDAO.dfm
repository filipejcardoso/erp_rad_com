object FUsuariosDAO: TFUsuariosDAO
  OldCreateOrder = False
  Height = 269
  Width = 570
  object RESTClient: TRESTClient
    BaseURL = 'http://api.com/api/v1'
    Params = <>
    HandleRedirects = True
    RaiseExceptionOn500 = False
    Left = 88
    Top = 48
  end
  object RESTRequest: TRESTRequest
    Client = RESTClient
    Params = <>
    Response = RESTResponse
    SynchronizedEvents = False
    Left = 88
    Top = 120
  end
  object RESTResponse: TRESTResponse
    Left = 88
    Top = 200
  end
end
