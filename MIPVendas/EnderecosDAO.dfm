object FEnderecosDAO: TFEnderecosDAO
  OldCreateOrder = False
  Height = 420
  Width = 467
  object RESTClient: TRESTClient
    BaseURL = 'http://api.com/api/v1'
    Params = <>
    HandleRedirects = True
    RaiseExceptionOn500 = False
    Left = 40
    Top = 32
  end
  object RESTRequest: TRESTRequest
    Client = RESTClient
    Params = <
      item
        Kind = pkURLSEGMENT
        name = 'ID'
        Options = [poAutoCreated]
      end>
    Resource = 'produtos/{ID}'
    Response = RESTResponse
    SynchronizedEvents = False
    Left = 40
    Top = 80
  end
  object RESTResponse: TRESTResponse
    Left = 40
    Top = 144
  end
end
