object FVendas: TFVendas
  Left = 0
  Top = 0
  Caption = 'Vendas'
  ClientHeight = 749
  ClientWidth = 1131
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 1131
    Height = 129
    Align = alTop
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGradientInactiveCaption
    Font.Height = 18
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    object LabelCabecalhoTitulo: TLabel
      Left = 40
      Top = 37
      Width = 693
      Height = 40
      Caption = '[PDV] ELETROBIDU COMERCIAL ELETRICA LTDA ME'
      Color = 432001
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object LabelCabecalhoSubTitulo: TLabel
      Left = 40
      Top = 83
      Width = 266
      Height = 20
      Caption = 'MIP VENDAS E CONTROLE DE ESTOQUE'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15790835
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object Label8: TLabel
      Left = 324
      Top = 83
      Width = 397
      Height = 20
      Caption = '(F7) CPF CLIENTE / (F8) VISUALIZAR PRODUTOS / (F12) SAIR'
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnShadow
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
  end
  object PanelVariavel: TPanel
    Left = 0
    Top = 129
    Width = 569
    Height = 620
    Align = alClient
    TabOrder = 1
    ExplicitHeight = 612
    object PanelPagamento: TPanel
      Left = 24
      Top = 24
      Width = 521
      Height = 257
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object GridPagamento: TStringGrid
        Left = 1
        Top = 1
        Width = 519
        Height = 255
        Align = alClient
        TabOrder = 0
        OnDrawCell = GridPagamentoDrawCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
    end
    object PanelDesconto: TPanel
      Left = 24
      Top = 296
      Width = 521
      Height = 346
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object Label2: TLabel
        Left = 24
        Top = 12
        Width = 122
        Height = 18
        Caption = 'C'#211'DIGO DO PEDIDO'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 141
        Width = 92
        Height = 18
        Caption = 'DESCONTO (%)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label4: TLabel
        Left = 160
        Top = 141
        Width = 96
        Height = 18
        Caption = 'DESCONTO (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label5: TLabel
        Left = 300
        Top = 141
        Width = 107
        Height = 18
        Caption = 'VALOR TOTAL(R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object LabelCliente: TLabel
        Left = 24
        Top = 100
        Width = 78
        Height = 24
        Caption = 'CLIENTE: '
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clDefault
        Font.Height = 25
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object EditCodigo: TEdit
        Left = 24
        Top = 36
        Width = 481
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 0
        OnKeyPress = EditCodigoKeyPress
      end
      object EditDescontoP: TEdit
        Left = 24
        Top = 165
        Width = 122
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnExit = EditDescontoPExit
        OnKeyPress = EditDescontoPKeyPress
      end
      object EditDescontoD: TEdit
        Left = 160
        Top = 165
        Width = 122
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnExit = EditDescontoDExit
        OnKeyPress = EditDescontoDKeyPress
      end
      object EditValorTotal: TEdit
        Left = 300
        Top = 165
        Width = 205
        Height = 48
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 40
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 3
      end
      object GroupBox1: TGroupBox
        Left = 24
        Top = 229
        Width = 481
        Height = 89
        Caption = 'VALOR DO PRODUTO (R$)'
        TabOrder = 4
        object LabelPrecoProduto: TLabel
          Left = 24
          Top = 27
          Width = 94
          Height = 50
          Caption = '00.00'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = 50
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
      end
    end
  end
  object PanelFixo: TPanel
    Left = 569
    Top = 129
    Width = 562
    Height = 620
    Align = alRight
    TabOrder = 2
    ExplicitHeight = 612
    object PanelProdutos: TPanel
      Left = 18
      Top = 24
      Width = 528
      Height = 401
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object GridProdutos: TStringGrid
        Left = 1
        Top = 1
        Width = 526
        Height = 399
        Align = alClient
        BorderStyle = bsNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = 18
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnDrawCell = GridProdutosDrawCell
        OnSelectCell = GridProdutosSelectCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
    end
    object PanelFinalizar: TPanel
      Left = 19
      Top = 437
      Width = 526
      Height = 202
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object Label6: TLabel
        Left = 24
        Top = 9
        Width = 133
        Height = 18
        Caption = 'VALOR RESTANTE (R$)'
        Color = 15790835
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6974058
        Font.Height = 18
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object EditValorRestante: TEdit
        Left = 24
        Top = 33
        Width = 481
        Height = 63
        Color = 5395281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 3198613
        Font.Height = 55
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object ButtonDinheiro: TButton
        Left = 24
        Top = 110
        Width = 145
        Height = 37
        Caption = 'DINHEIRO (F1)'
        TabOrder = 1
        OnClick = ButtonDinheiroClick
      end
      object ButtonCarteira: TButton
        Left = 24
        Top = 153
        Width = 145
        Height = 37
        Caption = 'CARTEIRA (F4)'
        TabOrder = 2
        OnClick = ButtonCarteiraClick
      end
      object ButtonCartao: TButton
        Left = 191
        Top = 110
        Width = 145
        Height = 37
        Caption = 'CART'#195'O (F2)'
        TabOrder = 3
        OnClick = ButtonCartaoClick
      end
      object ButtonCheque: TButton
        Left = 359
        Top = 110
        Width = 145
        Height = 37
        Caption = 'CHEQUE (F3)'
        TabOrder = 4
        OnClick = ButtonChequeClick
      end
      object ButtonVale: TButton
        Left = 191
        Top = 153
        Width = 145
        Height = 37
        Caption = 'VALE (F5)'
        TabOrder = 5
        OnClick = ButtonValeClick
      end
      object ButtonGaveta: TButton
        Left = 359
        Top = 153
        Width = 145
        Height = 37
        Caption = 'ABRIR GAVETA (F6)'
        TabOrder = 6
        OnClick = ButtonGavetaClick
      end
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 560
    Top = 400
  end
  object ActionList1: TActionList
    Left = 552
    Top = 456
    object F1: TAction
      Caption = 'F1'
      ShortCut = 112
      OnExecute = F1Execute
    end
    object F2: TAction
      Caption = 'F2'
      ShortCut = 113
      OnExecute = F2Execute
    end
    object F3: TAction
      Caption = 'F3'
      ShortCut = 114
      OnExecute = F3Execute
    end
    object F4: TAction
      Caption = 'F4'
      ShortCut = 115
      OnExecute = F4Execute
    end
    object F5: TAction
      Caption = 'F5'
      ShortCut = 116
      OnExecute = F5Execute
    end
    object F6: TAction
      Caption = 'F6'
      ShortCut = 117
      OnExecute = F6Execute
    end
    object F7: TAction
      Caption = 'F7'
      ShortCut = 118
      OnExecute = F7Execute
    end
    object F8: TAction
      Caption = 'F8'
      ShortCut = 119
    end
    object F12: TAction
      Caption = 'F12'
      ShortCut = 123
      OnExecute = F12Execute
    end
    object F9: TAction
      Caption = 'F9'
      ShortCut = 120
      OnExecute = F9Execute
    end
  end
  object HTTP: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 552
    Top = 520
  end
end
