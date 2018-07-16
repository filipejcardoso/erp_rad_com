object FPapelsDAO: TFPapelsDAO
  OldCreateOrder = False
  Height = 301
  Width = 472
  object RESTClient: TRESTClient
    BaseURL = 'http://api.com/api/v1'
    Params = <>
    HandleRedirects = True
    Left = 120
    Top = 48
  end
  object RESTRequest: TRESTRequest
    Client = RESTClient
    Params = <>
    Response = RESTResponse
    SynchronizedEvents = False
    Left = 120
    Top = 128
  end
  object RESTResponse: TRESTResponse
    Left = 120
    Top = 192
  end
end
