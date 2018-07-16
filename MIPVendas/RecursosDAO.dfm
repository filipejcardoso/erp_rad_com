object FResourceDAO: TFResourceDAO
  OldCreateOrder = False
  Height = 311
  Width = 623
  object RESTClient: TRESTClient
    Params = <>
    HandleRedirects = True
    Left = 64
    Top = 32
  end
  object RESTRequest: TRESTRequest
    Client = RESTClient
    Params = <>
    Response = RESTResponse
    SynchronizedEvents = False
    Left = 64
    Top = 104
  end
  object RESTResponse: TRESTResponse
    Left = 64
    Top = 184
  end
end
